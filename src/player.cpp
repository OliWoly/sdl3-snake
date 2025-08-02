#include <string>

#include "player.h"

#include "game_constants.h"

Player::Player()
    : Entity()
    {
        this->col={64, 209, 90, 255};
        this->set_colour(SNAKE_HEAD_COLOUR);
};

void Player::set_name(std::string name){
    this->name = name;
}

void Player::set_v(float v){
    this->v = v;
}

std::string Player::get_name(){
    return this->name;
}