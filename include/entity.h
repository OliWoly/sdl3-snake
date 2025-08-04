#pragma once
#include <optional>
#include <SDL3/SDL.h>

#include "position.h"
#include "colour.h"

class Entity{
    public:
        Position pos = {0, 0, 0};
        Colour col;
        
        float h = 0;        // Height
        float w = 0;        // Width
        float d = 0;        // Depth
        float v = 0;        // Velocity
        float acc = 0;      // Acceleration

        SDL_FRect rect;

        float ang_d;    // Angle (Degrees)
        float ang_r;    // Angle (Radians)


        explicit Entity();

        void updateRect();
        void draw(SDL_Renderer *renderer);

        void set_position(Position position);
        void set_positionALT(   std::optional<float> x, 
                                std::optional<float> y, 
                                std::optional<float> z);

        void set_colour(Colour colour);
        void set_colourALT(     std::optional<float> r, 
                                std::optional<float> g, 
                                std::optional<float> b,
                                std::optional<float> a);

        void set_dimensions(float w, float h, float d);
        void set_movementAttributes(float v, float acc);
};