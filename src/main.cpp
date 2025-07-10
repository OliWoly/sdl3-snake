// Oliwier Kulczycki
// SDL3 Implementation of the snake game.
#include <iostream>
#include <SDL3/SDL.h>
#include "../include/game.h"


int main(){
    Game game(1280, 720);
    // Start Game Loop
    while (game.get_running()){
        game.eventHandler();
        game.update();
        
        
        
        
        
        SDL_Delay(16);
    }


    // Clean
    game.cleanup();
    std::cout << "Finished.";
    return 0;
}