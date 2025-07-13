#pragma once
#include "game_extra.h"
#include "game_font.h"
#include "snake.h"
#include "apple.h"

class Game {
    private:
        Game_External ext{};
        Game_Mouse mouse{};
        Game_Counters counters;
        SDL_Event event{};
        Snake snake;
        Apple apple;

        Game_Font title;
        Game_Font frametime;
        Game_Font framerate;
        Game_Font score;

        bool running;
        float td{};
        float targetFrametime{};

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
                    void logic_textFrametime();

            // Init
            void initEngine();
            void initClasses();
                void initGrid(float heightRelative, int amountX, int amountY);
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
            void drawing_grid();
            void drawing_apple();

        // Getters
        void print_gridAttributes();
        bool get_running();

        // Setters
        void set_running(bool value);

};