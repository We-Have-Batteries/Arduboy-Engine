#ifndef PREFABS_H
#define PREFABS_H

#include "AbstractObject.h"
#include "GameObject.h"
#include "Setup.h"

class Prefabs{
public:
  static AbstractObject Air(){
    return AbstractObject();
  }

  static AbstractObject Brick(){
    CollidableImage brickPrefab = CollidableImage(75.3f, 0, 0, Collider(8, 8, 0, 0), nullptr);
    Setup::tinyfont.print("Making a brick\n");
    return AbstractObject(&brickPrefab);
  }

  static AbstractObject Player(){
    GameObject playerPrefab = GameObject(0, 0, 0, nullptr, Collider(8, 16, 0, 0), Rigidbody());
    return AbstractObject(&playerPrefab);
  }

  static AbstractObject Img() {
    Image img = Image(nullptr, 0, 0);
    // Setup::tinyfont.print("Making an image\n");
    return AbstractObject(&img);
  }
};

#endif