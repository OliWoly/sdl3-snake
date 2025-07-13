#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

class Game_Font{
    public:
        TTF_Font *font;
        SDL_Texture *texture;
        SDL_FRect rect = {0, 0, 0, 0};
        SDL_Color col = {255, 255, 255, 255};
        const char *text = "SAMPLE";

        explicit Game_Font();

        void draw(SDL_Renderer *renderer);
        void init(const char* fontPath, float fontSize, SDL_Color colour, SDL_Renderer *renderer);
        void init_font(const char* fontPath, float fontSize);
        void refreshText(SDL_Renderer *renderer);
        void changeText(const char* newText, SDL_Renderer *renderer);

        // Getters
        const char* get_text();
        void print_attributes();

        // Setters
        void set_text(const char *text);
        void set_positionCentreX(int min, int max);
        void set_positionCentreY(int min, int max);

};