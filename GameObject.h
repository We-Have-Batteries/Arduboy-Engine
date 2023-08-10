#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Rigidbody.h"
#include "CollidableImage.h"

class GameWorld;

class GameObject : public CollidableImage {
public:
    Rigidbody rb; // 4 Bytes

    GameObject() : CollidableImage() {
        rb = Rigidbody();
    }

    GameObject(float x, float y, uint8_t flags, uint8_t* img, Collider col, Rigidbody rb) : CollidableImage(x, y, flags, col, img) {
        this->rb = rb;
    }
};

#endif