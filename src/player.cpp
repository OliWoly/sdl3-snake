#include <string>

#include "player.h"

Player::Player()
    : Entity()
    {

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