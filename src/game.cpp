#include <iostream>
#include <optional>
#include <sstream>
#include <chrono>
#include "../include/game.h"
#include "../include/apple.h"
#include "../include/game_constants.h"

Game::Game(int w, int h){

    // General
    this->running = true;

    // GameGrid
    this->grid.tile_width = 20;
    this->grid.tile_height = 20;

    // GameExternal
    this->ext.screenWidth = w;
    this->ext.screenHeight = h;
    this->ext.window = nullptr;
    this->ext.renderer = nullptr;

    // GameMouse
    this->mouse.x = 0;
    this->mouse.y = 0;
    this->mouse.gx = 0;
    this->mouse.gy = 0;

    // Init Methods
    this->initEngine();
    this->initClasses();
};

// Class Methods
void Game::update(){
    while (this->running){
        auto start = std::chrono::high_resolution_clock::now();
        this->eventHandler();
        this->update_fixed();
        this->updateStatisticsText();

        this->drawing();



        {   // For Calculating Time Delta.
            auto end = std::chrono::high_resolution_clock::now();  // End time
            auto tdelta = end - start;
            std::chrono::duration<double, std::milli> ms = tdelta;
            this->td = ms.count();  // Update Time Delta
        }
    }
}
void Game::update_fixed(){
    // Refresh checking counters.
    this->update_counters();


    // 20HZ
    if (this->counters.sinceLastSnakeMove > SNAKE_MOVE_RATE){
        this->logic_snake();
        // Reset counter
        this->counters.lastSnakeMove = std::chrono::high_resolution_clock::now();
    }
    // 240HZ
    if (this->counters.sinceLastPhysicsCalc > PHYSICS_REFRESH_RATE){
        this->logic_textTitle();
        // Reset counter
        this->counters.lastPhysicsCalc = std::chrono::high_resolution_clock::now();
    }
    // 2HZ
    if (this->counters.sinceLastDebugUpdate > DEBUG_REFRESH_RATE) {
        this->updateDebugText();
        // Reset counter
        this->counters.lastDebugUpdate = std::chrono::high_resolution_clock::now();
    }
    
}
void Game::update_counters(){
    auto now = std::chrono::high_resolution_clock::now();

    this->counters.sinceLastSnakeMove = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->counters.lastSnakeMove).count();
    this->counters.sinceLastPhysicsCalc = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->counters.lastPhysicsCalc).count();
    this->counters.sinceLastDebugUpdate = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->counters.lastDebugUpdate).count();
}

void Game::logic_snake(){
    // Move body.
    this->snake.step_body();

    // Move head.
    switch (this->snake.direction){
        case 0:
            this->snake.head.set_v(this->grid.tile_height);
            this->snake.step_up();
            break;

        case 1:
            this->snake.head.set_v(this->grid.tile_width);
            this->snake.step_left();
            break;

        case 2:
            this->snake.head.set_v(this->grid.tile_height);
            this->snake.step_down();
            break;
            
        case 3:
            this->snake.head.set_v(this->grid.tile_width);
            this->snake.step_right();
            break;

        default:
            break;
    }

}
void Game::logic_textTitle(){
    this->move_titleText();
}
void Game::move_titleText(){
    //this->title.rect.x += 0.2 * this->td;
}
void Game::updateDebugText(){
    this->logic_textFrametime();
    this->logic_textFramerate();
}
void Game::updateStatisticsText() {
    this->logic_textPosition();
    this->logic_textScore();
}
void Game::logic_textFrametime() {
    std::ostringstream oss;
    oss << "Frametime: " << this->td << " ms";
    std::string debugText = oss.str();
    const char* debugTextF = debugText.c_str();
    this->frametime.changeText(debugTextF, this->ext.renderer);
}
void Game::logic_textFramerate() {
    std::ostringstream oss;
    int framerate = int(this->td * 1000);
    oss << "FPS: " << framerate;
    std::string debugText = oss.str();
    const char* debugTextF = debugText.c_str();
    this->framerate.changeText(debugTextF, this->ext.renderer);
}
void Game::logic_textPosition() {
    std::ostringstream oss;
    int framerate = int(this->td * 1000);
    oss << "X: " << this->snake.head.pos.x << " Y: " << this->snake.head.pos.y;
    std::string debugText = oss.str();
    const char* debugTextF = debugText.c_str();
    this->snakePosition.changeText(debugTextF, this->ext.renderer);
    this->snakePosition.rect.x = this->ext.screenWidth - this->snakePosition.rect.w - SCREEN_PADDING_X;
}
void Game::logic_textScore() {
    std::ostringstream oss;
    int framerate = int(this->td * 1000);
    oss << "Score: " << this->snake.body.size();
    std::string debugText = oss.str();
    const char* debugTextF = debugText.c_str();
    this->score.changeText(debugTextF, this->ext.renderer);
    this->score.rect.x = this->ext.screenWidth - this->score.rect.w - SCREEN_PADDING_X;
}





void Game::drawing(){
    SDL_SetRenderDrawColor(this->ext.renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->ext.renderer);


    this->drawing_grid();
    this->drawing_snake();
    this->drawing_apple();
    this->drawing_text();


    SDL_RenderPresent(this->ext.renderer);
}
void Game::drawing_snake(){
    this->snake.head.draw(this->ext.renderer);
    for (int i=0; i < this->snake.body.size(); i++){
        this->snake.body[i].draw(this->ext.renderer);
    }

}
void Game::drawing_text(){
    this->title.draw(this->ext.renderer);
    this->frametime.draw(this->ext.renderer);
    this->framerate.draw(this->ext.renderer);
    this->snakePosition.draw(this->ext.renderer);
    this->score.draw(this->ext.renderer);
}
void Game::drawing_grid(){
    this->grid.rect.x = this->grid.xO;
    this->grid.rect.y = this->grid.yO;
    this->grid.rect.w = this->grid.width_pixels;
    this->grid.rect.h = this->grid.height_pixels;
    SDL_SetRenderDrawColor(this->ext.renderer, this->grid.primaryCol.r, this->grid.primaryCol.g, this->grid.primaryCol.b, this->grid.primaryCol.a);
    SDL_RenderFillRect(this->ext.renderer, &this->grid.rect);

    this->grid.rect.w = this->grid.tile_width;
    this->grid.rect.h = this->grid.tile_height;

    // Preset draw colour to avoid calling it each time.
    SDL_SetRenderDrawColor(this->ext.renderer, this->grid.secondaryCol.r, this->grid.secondaryCol.g, this->grid.secondaryCol.b, this->grid.secondaryCol.a);


    // j is x
    // i is y
    for (int j=0; j < this->grid.width_tiles; j++){
        for (int i=0; i < this->grid.height_tiles; i++){
            if ((i+j)%2 == 1){
                this->grid.rect.x = this->grid.xO + j * this->grid.tile_width;
                this->grid.rect.y = this->grid.yO + i * this->grid.tile_height;

                SDL_RenderFillRect(this->ext.renderer, &this->grid.rect);
            }
        }
    }
}
void Game::drawing_apple(){
    this->apple.draw(this->ext.renderer);
}





void Game::eventHandler(){
    while (SDL_PollEvent(&this->event)) {
        this->closeWithOS();
        this->handleKeyboard();
    }
}
void Game::handleKeyboard(){
    this->handleKeyboard_KeyDown();
}
void Game::handleKeyboard_KeyDown(){
    if (this->event.type == SDL_EVENT_KEY_DOWN){
        switch (this->event.key.key) {
            case SDLK_ESCAPE:
                this->running = false;
                break;

            // WASD
            case SDLK_W:
                if (this->snake.get_direction() != 2){
                    this->snake.set_direction(0);
                }
                break;

            case SDLK_A:
                if (this->snake.get_direction() != 3){
                    this->snake.set_direction(1);
                }
                break;

            case SDLK_S:
                if (this->snake.get_direction() != 0){
                    this->snake.set_direction(2);
                }
                break;

            case SDLK_D:
                if (this->snake.get_direction() != 1){
                    this->snake.set_direction(3);
                }
                break;

            case SDLK_F:
                this->snake.extend();
                break;

            default:
                break;
        }
    }
}
void Game::closeWithOS(){
    if (this->event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
        this->running = false;
    } 
}




void Game::initGrid(float heightRelative, int amountX, int amountY){
    this->grid.heightRelative = heightRelative;
    this->grid.width_tiles = amountX;
    this->grid.height_tiles = amountY;

    // Assumed height.
    this->grid.height_pixels = this->ext.screenHeight * this->grid.heightRelative;
    this->grid.tile_height = this->grid.height_pixels / this->grid.height_tiles;


    // If Square Tiles.
    this->grid.tile_width = this->grid.tile_height;
    this->grid.width_pixels = this->grid.tile_width * this->grid.width_tiles;
    // Recalculate Height for accuracy.
    this->grid.height_pixels = this->grid.tile_height * this->grid.height_tiles;

    this->grid.xO = (this->ext.screenWidth/2) - (this->grid.width_pixels/2);
    this->grid.yO = (this->ext.screenHeight/2) - (this->grid.height_pixels/2);
}
void Game::initClasses(){
    
    // Grid
    this->initGrid(0.8, 40, 25);
    //this->print_gridAttributes();
    
    // Snake
    this->snake = Snake();
        // Assigning default values for head.
    {
        this->snake.head.set_positionALT(this->grid.xO, this->grid.yO, std::nullopt);
        this->snake.head.set_dimensions(this->grid.tile_width, this->grid.tile_height, 1);
        this->snake.head.set_colourALT(std::nullopt, 0, 0,std::nullopt);
    }

    // Apple
    this->apple = Apple();
    {
        this->apple.set_positionALT(this->grid.tile_width*4, this->grid.tile_height*4, 0);
    }
    std::cout << this->apple.pos.x << ", " << this->apple.pos.y << std::endl;
    std::cout << this->apple.col.r << ", " << this->apple.col.g << ", " << this->apple.col.b << std::endl;


    // Text
    // Title
    this->title.init("../recourses/fonts/Daydream.ttf",
                    24,
                    SDL_Color{255, 255, 255, 255},
                    this->ext.renderer);
    this->title.changeText("SNAKE", this->ext.renderer);
    this->title.set_positionCentreX(this->grid.xO, this->grid.xO + this->grid.width_pixels);

    // Debug Text
    // Y Position is handled by lowest variable.
    // X Position is handled in the text logic function.
    this->initDebugText();
    this->initStatisticsText();

}
void Game::initEngine(){
    // SDL Initialise
    SDL_Init(SDL_INIT_VIDEO);

    

    // Window Initialise
    this->ext.window = SDL_CreateWindow("SDL3-Snake", this->ext.screenWidth, this->ext.screenHeight, 0);
    if (!this->ext.window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
    }
    
    // Renderer Initialise
    this->ext.renderer = SDL_CreateRenderer(this->ext.window, NULL);
    if (!this->ext.renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
    }

    // Text
    TTF_Init();

    // Misc
    SDL_SetRenderVSync(this->ext.renderer, SDL_RENDERER_VSYNC_DISABLED);
}
void Game::cleanup(){
    // First check if pointer exists to avoid freeing nullptr.
    if (this->title.font){
        TTF_CloseFont(this->title.font);
        this->title.font = NULL;
    }
    
    if (this->ext.renderer){
        SDL_DestroyRenderer(this->ext.renderer);
        this->ext.renderer = NULL;
    }
    if (this->ext.window){
        SDL_DestroyWindow(this->ext.window);
        this->ext.window = NULL;
    }
    
    SDL_Quit();
    TTF_Quit();
}
void Game::initDebugText() {
    // lowest will set the current highest (confusing i know) available coordinate i pixels
    // to be drawn to not interfere with more text.
    // avoids further unneeded maths.
    // updates every tim e anew text box is added in debug.
    float lowest = 0;   // initial vertical position.

    this->frametime.init("../recourses/fonts/Helvetica.ttf", 14, SDL_Color{0, 255, 0, 255},this->ext.renderer);
    this->frametime.changeText("Frametime: ", this->ext.renderer);
    lowest = this->frametime.rect.y + this->frametime.rect.h;

    this->framerate.init("../recourses/fonts/Helvetica.ttf", 14, SDL_Color{0, 255, 0, 255},this->ext.renderer);
    this->framerate.rect.y = lowest;
    lowest += this->framerate.rect.h;
}
void Game::initStatisticsText() {
    float lowest = 0;

    this->snakePosition.init("../recourses/fonts/DayDream.ttf",
                            18,
                            SDL_Color{200, 40, 180, 255},
                            this->ext.renderer);
    lowest = this->snakePosition.rect.y + this->snakePosition.rect.h;

    this->score.init("../recourses/fonts/Daydream.ttf",
                    18,
                    SDL_Color{200, 40, 180, 255},
                    this->ext.renderer);
    this->score.rect.y = lowest;
    lowest += this->score.rect.h;
}





// Getters
void Game::print_gridAttributes(){
    std::cout << "Grid Width in Tiles: " << this->grid.width_tiles << std::endl;
    std::cout << "Grid Height in Tiles: " << this->grid.height_tiles << std::endl;

    std::cout << "Grid Width in Pixels: " << this->grid.width_pixels << std::endl;
    std::cout << "Grid Height in Pixels: " << this->grid.height_pixels << std::endl;

    std::cout << "Tile Width in Pixels: " << this->grid.tile_width << std::endl;
    std::cout << "Tile Height in Pixels: " << this->grid.tile_height << std::endl;

    std::cout << "X Origin: " << this->grid.xO << std::endl;
    std::cout << "Y Origin: " << this->grid.yO << std::endl;
}

bool Game::get_running(){
    return this->running;
}

// Setters
void Game::set_running(bool value){
    this->running = value;
}