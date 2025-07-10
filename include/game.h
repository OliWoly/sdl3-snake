#pragma once
#include "SDL3/SDL.h"

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

class Game {
    private:
        Game_External ext;
        Game_Mouse mouse;
        SDL_Event event;
        bool running;
        float td;
        float targetFrametime;

    public:
        // Explicit is good practice.
        explicit Game(int w, int h);

        // Methods
        void initEngine();
        void eventHandler();
        void closeWithOS();
        void handleKeyboard();
        void handleKeyboard_KeyDown();

        // Getters
        bool get_running();

        // Setters
        void set_running(bool value);

};