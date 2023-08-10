#ifndef PREFABS_H
#define PREFABS_H

#include "AbstractObject.h"
#include "GameObject.h"

class Prefabs{
public:
  static AbstractObject Air(){
    return AbstractObject();
  }

  static AbstractObject Brick(){
    CollidableImage brickPrefab = CollidableImage(0, 0, 0, Collider(8, 8, 0, 0), nullptr);
    return AbstractObject(&brickPrefab);
  }

  static AbstractObject Player(){
    GameObject playerPrefab = GameObject(0, 0, 0, nullptr, Collider(8, 16, 0, 0), Rigidbody());
    return AbstractObject(&playerPrefab);
  }
};

#endif