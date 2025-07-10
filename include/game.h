#pragma once
#include <SDL3/SDL.h>
#include "game_extra.h"
#include "snake.h"

class Game {
    private:
        Game_External ext;
        Game_Mouse mouse;
        SDL_Event event;

        Snake snake;

        bool running;
        float td;
        float targetFrametime;

    public:
        // Explicit is good practice.
        explicit Game(int w, int h);

        // Methods
            // Running
            void update();
            void update_fixed();

            // Init
            void initEngine();
            void initClasses();
            void cleanup();
        
            // Events
            void eventHandler();
            void closeWithOS();
            void handleKeyboard();
            void handleKeyboard_KeyDown();

            // Drawing
            void drawing();
            void drawing_snake();

        // Getters
        bool get_running();

        // Setters
        void set_running(bool value);

};