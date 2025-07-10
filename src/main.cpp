// Oliwier Kulczycki
// SDL3 Implementation of the snake game.
#include <iostream>
#include <SDL3/SDL.h>

void cleanup(SDL_Window *window);

int main(){
    std::cout << "HELLO WORLD" << std::endl;

    if (!SDL_Init(SDL_INIT_VIDEO)){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", "Error initialising SDL3.", nullptr);
        return 1;
    }

    int w = 1280;
    int h = 720;
    SDL_Window *window = SDL_CreateWindow("SDL3-Snake", w, h, 0);

    if (!window){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", "Error creating window.", window);
        return 1;
    }

    bool running = true;
    while (running){
        SDL_Event event { 0 };
        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_EVENT_QUIT:{
                    running = false;
                    break;
                }
            }
        } 
    }




    cleanup(window);
}

void cleanup(SDL_Window *window){
    SDL_DestroyWindow(window);
    SDL_Quit();
}