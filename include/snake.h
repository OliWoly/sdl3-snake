#pragma once
#include <vector>

#include "player.h"
#include "entity.h"

class Snake{
    public:
        Player head;
        std::vector<Entity> body;
        explicit Snake();
};