#include "../include/collision.h"

Collision::Collision()
{

}

bool Collision::collide(Entity e1, Entity e2){
    return (e1.pos.x < e2.pos.x + e2.w &&
            e1.pos.x + e1.w > e2.pos.x &&
            e1.pos.y < e2.pos.y + e2.h &&
            e1.pos.y + e1.h > e2.pos.y);
}

