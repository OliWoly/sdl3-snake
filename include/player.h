#pragma once
#include <string>

#include "entity.h"


class Player : public Entity{
    private:
        std::string name = "Player";
    
    public:
        float v;
        explicit Player();
        void set_name(std::string name);
        void set_v(float v);

        std::string get_name();
};

