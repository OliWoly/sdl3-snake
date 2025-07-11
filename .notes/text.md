# Displaying text in SDL3
# Inlcuding:
```c
#include <SDL3_ttf/SDL_ttf.h>
```
In the cmake file, copy what was done for SDL3 and redo it for SDL3_ttf.
SDl3_ttf was also downloaded through homebrew on macos.

# Code

```c
// Text
    this->font = TTF_OpenFont("../recourses/fonts/Daydream.ttf", 24);
    if (!this->font){
        std::cout << "ERROR FONT" << std::endl;
    }

    SDL_Surface *surface = TTF_RenderText_Blended(this->font, "Snake", 0, this->textColour);
    if (!surface){
        std::cout << "ERROR SURFACE" << std::endl;
    }

    // Copy size from the surface.
    this->textRect.w = surface->w;
    this->textRect.h = surface->h;

    this->textImage = SDL_CreateTextureFromSurface(this->ext.renderer, surface);
    SDL_DestroySurface(surface);
    surface = NULL;
    if (!this->textImage){
        std::cout << "ERROR CREATING TEXTURE FROM SURFACE" << std::endl;
    }
    SDL_SetTextureScaleMode(this->textImage, SDL_SCALEMODE_NEAREST);
```

```c
SDL_RenderTexture(this->ext.renderer, this->textImage, NULL, &this->textRect);
```
This draws the final output: the texture containing the text.
The Null could be used as a rect; passing through a rect tells it what part of the texture to draw, the second rect reference tells it bascially how big to draw it as and where. keeping it as Null draws it from 0 0 and stretching it to the entirety of the screen.