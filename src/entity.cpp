#include "entity.h"

Entity::Entity(){
    this->col.r = 255;
    this->col.g = 0;
    this->col.b = 0;
    this->col.a = 255;

    
};

// Class Methods
void Entity::draw(SDL_Renderer *renderer){
    this->rect.x = this->pos.x;
    this->rect.y = this->pos.y;
    this->rect.w = this->w;
    this->rect.h = this->h;
    SDL_SetRenderDrawColor(renderer, this->col.r, this->col.g, this->col.b, this->col.a);
    SDL_RenderFillRect(renderer, &rect);
}


// Getters


// Setters

void Entity::set_position(Position position){
    this->pos = position;
}

void Entity::set_positionALT(std::optional<float> x, std::optional<float> y, std::optional<float> z){
    if (x.has_value()){
        this->pos.x = x.value();
    }

    if (y.has_value()){
        this->pos.y = y.value();
    }

    if (z.has_value()){
        this->pos.z = z.value();
    }
}

void Entity::set_colour(Colour colour){
    this->col = colour;
}

void Entity::set_colourALT(std::optional<float> r, std::optional<float> g, std::optional<float> b, std::optional<float> a){
    if (r.has_value()){
        this->col.r = r.value();
    }

    if (g.has_value()){
        this->col.g = g.value();
    }

    if (b.has_value()){
        this->col.b = b.value();
    }

    if (a.has_value()){
        this->col.a = a.value();
    }
}

void Entity::set_dimensions(float w, float h, float d){
    this->w = w;
    this->h = h;
    // If unsure keep depth at 1.
    this->d = d;
}

void Entity::set_movementAttributes(float v, float acc){
    this->v = v;
    this->acc = acc;
}