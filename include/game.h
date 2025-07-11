#pragma once
#include "game_extra.h"
#include "game_font.h"
#include "snake.h"

class Game {
    private:
        Game_External ext;
        Game_Mouse mouse;
        Game_Counters counters;
        SDL_Event event;
        Snake snake;

        Game_Font title;
        Game_Font debug;

        bool running;
        float td;
        float targetFrametime;

    public:
        // Explicit is good practice.
        explicit Game(int w, int h);
        Game_Grid grid;

        // Methods
            // Running
            void update();
            void update_fixed();
            void update_counters();

            // Logic
            void logic();
            void logic_snake();
            void logic_text();
                void move_titleText();
                void updateDebugText();

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