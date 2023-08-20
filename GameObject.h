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

  GameObject(float x, float y, uint8_t flags, 
  uint8_t colWidth, uint8_t colHeight, int colOffsetX, int colOffsetY, uint8_t* img) : 
  CollidableImage(x, y, flags, colWidth, colHeight, colOffsetX, colOffsetY, img) {
    rb = Rigidbody();
  }

  GameObject(float x, float y, uint8_t flags, uint8_t* img, Collider col, Rigidbody rb) : 
  CollidableImage(x, y, flags, col, img) {
    this->rb = rb;
  }

  void SetVelocity(float xSpeed, float ySpeed) override{
    SetXSpeed(xSpeed);
    SetYSpeed(ySpeed);
  }
  void SetXSpeed(float xSpeed) override{
    if (xSpeed > 655.35){
      xSpeed = 655.35;
      signStorage |= 1 << 5;
    }
    if (xSpeed < -655.35){
      xSpeed = -655.35;
      signStorage &= ~(1 << 5);
    }
    rb.SetXSpeed(xSpeed);
  }
  void SetYSpeed(float ySpeed) override{
    if (ySpeed > 655.35){
      ySpeed = 655.35;
      signStorage |= 1 << 4;
    }
    if (ySpeed < -655.35){
      ySpeed = -655.35;
      signStorage &= ~(1 << 4);
    }
    rb.SetYSpeed(ySpeed);
  }
};

#endif