#include <iostream>
#include <optional>
#include <chrono>
#include <thread>
#include "../include/game.h"

const float PHYSICS_REFRESH_RATE = 1000.0/240;
const float SNAKE_MOVE_RATE = 1000.0/60;

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
        this->drawing();



        {   // For Calculating Time Delta.
            auto end = std::chrono::high_resolution_clock::now();  // End time
            auto tdelta = end - start;
            std::chrono::duration<double, std::milli> ms = tdelta;
            this->td = ms.count();  // Update Time Delta
        }
    }
}

void Game::logic_snake(){
    // Move body.
    this->snake.step_body();

    // Move head.
    switch (this->snake.direction){
        case 0:
            this->snake.head.set_v(this->grid.tile_height);
            this->snake.step_up();
            this->counters.lastSnakeMove = std::chrono::high_resolution_clock::now();
            break;

        case 1:
            this->snake.head.set_v(this->grid.tile_width);
            this->snake.step_left();
            this->counters.lastSnakeMove = std::chrono::high_resolution_clock::now();
            break;

        case 2:
            this->snake.head.set_v(this->grid.tile_height);
            this->snake.step_down();
            this->counters.lastSnakeMove = std::chrono::high_resolution_clock::now();
            break;
            
        case 3:
            this->snake.head.set_v(this->grid.tile_width);
            this->snake.step_right();
            this->counters.lastSnakeMove = std::chrono::high_resolution_clock::now();
            break;

        default:
            break;
    }

}

void Game::update_fixed(){
    this->update_counters();
    if (this->counters.sinceLastSnakeMove > SNAKE_MOVE_RATE){
        this->logic_snake();
    }
    
}

void Game::update_counters(){
    auto now = std::chrono::high_resolution_clock::now();

    this->counters.sinceLastSnakeMove = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->counters.lastSnakeMove).count();
}

void Game::drawing(){
    SDL_SetRenderDrawColor(this->ext.renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->ext.renderer);


    this->drawing_snake();


    SDL_RenderPresent(this->ext.renderer);
}

void Game::drawing_snake(){
    this->snake.head.draw(this->ext.renderer);

    std::cout << this->snake.body.size() << std::endl;
    for (int i=0; i < this->snake.body.size(); i++){
        this->snake.body[i].draw(this->ext.renderer);
    }

}

void Game::closeWithOS(){
    if (this->event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
        this->running = false;
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

void Game::eventHandler(){
    while (SDL_PollEvent(&this->event)) {
        this->closeWithOS();
        this->handleKeyboard();
    }
}

void Game::initClasses(){
    this->snake = Snake();
    // Assigning default values for head.
    this->snake.head.set_positionALT(0, 0, std::nullopt);
    this->snake.head.set_dimensions(this->grid.tile_width, this->grid.tile_height, 1);
    this->snake.head.set_colourALT(std::nullopt, 0, 0,std::nullopt);
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
}

void Game::cleanup(){
    if (!this->running){
        SDL_DestroyRenderer(this->ext.renderer);
        SDL_DestroyWindow(this->ext.window);
    }
}

// Getters

bool Game::get_running(){
    return this->running;
}

// Setters

void Game::set_running(bool value){
    this->running = value;
}