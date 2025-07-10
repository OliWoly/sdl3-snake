#pragma once
#include <SDL3/SDL.h>

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