#include "../include/collision.h"

Collision::Collision()
{

}

bool Collision::collide(Entity e1, Entity e2){
    // Pure check.
    if (e1.pos.x < e2.pos.x + e2.rect.w &&
        e1.pos.x + e1.rect.w > e2.pos.x &&
        e1.pos.y < e2.pos.y + e2.rect.h &&
        e1.pos.y + e1.rect.h > e2.pos.y) {

            return true;
        }
    else {
        return false;
    }
}
