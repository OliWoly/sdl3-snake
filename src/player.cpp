#include <iostream>
#include "player.h"

Player::Player(int x, int y){
    this->pos.x = x;
    this->pos.y = y;
    this->pos.z = 0;
    
    this->col.r = 255;
    this->col.g = 0;
    this->col.b = 0;
    this->col.a = 255;

    
}