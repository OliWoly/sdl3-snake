#include <iostream>
#include <optional>
#include <thread>
#include "../include/game.h"


Game::Game(int w, int h){

    // General
    this->running = true;

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
    this->drawing();
}

void Game::drawing(){
    // Cleanup
    SDL_SetRenderDrawColor(this->ext.renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->ext.renderer);

    // Do Drawing
    std::thread drawer_snake(&Game::drawing_snake, this);
    drawer_snake.join();

    // Present all.
    SDL_RenderPresent(this->ext.renderer);
}

void Game::drawing_snake(){
    this->snake.head.draw(this->ext.renderer);

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
        if (this->event.key.key == SDLK_ESCAPE){
            this->running = false;
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
    this->snake.head.set_positionALT(100, 100, std::nullopt);
    this->snake.head.set_dimensions(200, 200, 1);
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