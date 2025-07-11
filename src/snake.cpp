#include <iostream>

#include "snake.h"
#include "entity.h"

Snake::Snake(){
    
}

void Snake::extend(){
    Entity segment;
    segment.set_dimensions(this->head.w, this->head.h, 1);
    segment.set_colourALT(255, 255, 100,std::nullopt);
    //segment.set_position(this->head.pos);
    this->body.push_back(segment);
}

void Snake::move(float dx, float dy, float dz){
    // D stands for difference.
    this->head.pos.x += dx;
    this->head.pos.y += dy;
    this->head.pos.z += dz;
}

void Snake::step(float mx, float my, float mz){
    // Uses player velocity to determine move distance.
    // M stands for multiplier
    // Seperate for each direction
    this->head.pos.x += this->head.v * mx;
    this->head.pos.y += this->head.v * my;
    this->head.pos.z += this->head.v * mz;
}

void Snake::step_up() {
    this->head.pos.y -= this->head.v;
}

void Snake::step_left() {
    this->head.pos.x -= this->head.v;
}

void Snake::step_down() {
    this->head.pos.y += this->head.v;
}

void Snake::step_right() {
    this->head.pos.x += this->head.v;
}

void Snake::step_body(){
    for (int i=this->body.size()-1; i > -1; i--){
        if (i == 0){
            this->body[i].set_position(this->head.pos);
            break;
        }
        this->body[i].set_position(this->body[i-1].pos);
    }
}

void Snake::set_direction(int direction){
    this->direction = direction;
}

int Snake::get_direction(){
    return this->direction;
}