#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "game_extra.h"
#include "snake.h"

class Game {
    private:
        Game_External ext;
        Game_Mouse mouse;
        Game_Counters counters;
        SDL_Event event;

        Snake snake;

        bool running;
        float td;
        float targetFrametime;

    public:
        // Explicit is good practice.
        explicit Game(int w, int h);
        Game_Grid grid;
        TTF_Font *font;
        SDL_Texture *textImage;
        SDL_FRect textRect;
        SDL_Color textColour={255, 255, 255, 255};

        // Methods
            // Running
            void update();
            void update_fixed();
            void update_counters();

            // Logic
            void logic();
            void logic_snake();

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
            void drawing_text();

        // Getters
        bool get_running();

        // Setters
        void set_running(bool value);

};