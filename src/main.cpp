// Oliwier Kulczycki
// SDL3 Implementation of the snake game.
#include <iostream>
#include <SDL3/SDL.h>
#include "../include/game.h"


int main(){
    std::cout << "Running." << std::endl;
    Game game(1280, 720);
    
    game.initEngine();
    while (game.get_running() == true){
        game.eventHandler();
        SDL_Delay(16);
    }




}