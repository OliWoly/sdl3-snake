#include "../include/apple.h"

Apple::Apple()
    : Entity(){

        this->col={255, 0, 255, 255};

}

void Apple::respawn(Position position){
    this->pos.x = position.x;
    this->pos.y = position.y;
}