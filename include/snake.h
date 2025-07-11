#pragma once
#include <vector>

#include "player.h"
#include "entity.h"

class Snake{
    public:
        Player head;
        std::vector<Entity> body;
        int direction = -1;
        explicit Snake();

        // Class Methods
        void move(float dx, float dy, float dz);
        
        
        void step(float mx, float my, float mz);
        void extend();
        void step_up();
        void step_left();
        void step_down();
        void step_right();
        void step_body();

        void set_direction(int direction);
        int get_direction();
};