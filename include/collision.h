#pragma once
#include "entity.h"

class Collision{
    private:

    public:
    Collision();
    static bool collide(Entity e1, Entity e2);
};
