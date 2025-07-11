#pragma once
#include <SDL3/SDL.h>

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
};

class Game_Counters {
    public:
        std::chrono::high_resolution_clock::time_point lastSnakeMove = std::chrono::high_resolution_clock::now();
        float sinceLastSnakeMove;
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