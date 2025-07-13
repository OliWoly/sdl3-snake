#pragma once
#include <SDL3/SDL.h>
#include "colour.h"
#include <chrono>

class Game_Grid{
    public:
        int width_tiles;
        int height_tiles;

        int width_pixels;
        int height_pixels;

        // In Pixels
        int tile_width;
        int tile_height;

        int xO;
        int yO;

        // % of Vertical of the screen to make the grid
        // Value of 0.8 = 80% of the screen height, etc.
        float heightRelative;

        Colour primaryCol{17, 17, 17, 255};
        Colour secondaryCol{35, 35, 35, 255};

        SDL_FRect rect;
};

class Game_Counters {
    public:
        std::chrono::high_resolution_clock::time_point lastSnakeMove = std::chrono::high_resolution_clock::now();
        float sinceLastSnakeMove;

        std::chrono::high_resolution_clock::time_point lastPhysicsCalc = std::chrono::high_resolution_clock::now();
        float sinceLastPhysicsCalc;

        std::chrono::high_resolution_clock::time_point lastDebugUpdate = std::chrono::high_resolution_clock::now();
        float sinceLastDebugUpdate;
};

class Game_External {
    public:
        int screenWidth;
        int screenHeight;
        SDL_Window *window;
        SDL_Renderer *renderer;
};

class Game_Mouse {
    public:
        float x;
        float y;
        float gx;
        float gy;
};