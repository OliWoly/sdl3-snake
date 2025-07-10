#pragma once
#include "SDL3/SDL.h"
#include "position.h"
#include "colour.h"

class Player{
    private:
        Position pos;
        Colour col;

    public:
        explicit Player(int x, int y);
    
};

