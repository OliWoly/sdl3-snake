// Oliwier Kulczycki
// SDL3 Implementation of the snake game.
#include <iostream>
#include <SDL3/SDL.h>
#include "../include/game.h"


int main(){
    Game game(1280, 720);
    game.update();


    // Clean
    game.cleanup();
    std::cout << "Finished.";
    return 0;
}