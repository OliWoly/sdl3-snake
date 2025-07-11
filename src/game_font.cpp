#include <iostream>
#include "../include/game_font.h"

Game_Font::Game_Font(){

}

void Game_Font::draw(SDL_Renderer *renderer){
    SDL_RenderTexture(renderer, this->texture, NULL, &this->rect);
}

void Game_Font::init(const char* fontPath, float fontSize, SDL_Color colour, SDL_Renderer *renderer){
    // Set new colour.
    this->col = colour;
    this->init_font(fontPath, fontSize);
    this->refreshText(renderer);
    
    
    
}

void Game_Font::init_font(const char* fontPath, float fontSize){
    // Init Font
    this->font = TTF_OpenFont(fontPath, fontSize);
    if (!this->font){
        std::cout << "Error Initialising Font" << SDL_GetError() << std::endl;
    }
}

void Game_Font::refreshText(SDL_Renderer *renderer){
    // Only a surface can be made from text, have to convert to texture later.
    SDL_Surface *surface = TTF_RenderText_Blended(this->font, this->text, 0, this->col);
    if (!surface){
        std::cout << "Error Initialising Surface" << SDL_GetError() << std::endl;
    }

    // Copy size from the surface before freeing the surface.
    this->rect.w = surface->w;
    this->rect.h = surface->h;

    // Create Texture from the Surface.
    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!this->texture){
        std::cout << "Error Initialising Texture from Surface" << SDL_GetError() << std::endl;
    }

    // Finally Destroy the Surface.
    SDL_DestroySurface(surface);
    surface = NULL;
}

void Game_Font::changeText(const char *newText, SDL_Renderer *renderer){
    this->set_text(newText);
    this->refreshText(renderer);
}


// Getters
const char* Game_Font::get_text(){
    return this->text;
}

// Setters
void Game_Font::set_text(const char* text){
    this->text = text;
}

    