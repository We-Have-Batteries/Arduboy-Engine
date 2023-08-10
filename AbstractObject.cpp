#include "AbstractObject.h"

AbstractObject::AbstractObject(){
  objectPtr = nullptr;
  type = INVALID;
}

AbstractObject::AbstractObject(void* objPtr, ObjectTypes type){
  objectPtr = objPtr;
  this->type = type;
}

AbstractObject::AbstractObject(Image* objPtr){
  objectPtr = objPtr;
  type = IMAGE;
}

AbstractObject::AbstractObject(CollidableImage* objPtr){
  objectPtr = objPtr;
  type = COLLIDABLEIMAGE;
}

AbstractObject::AbstractObject(GameObject* objPtr){
  objectPtr = objPtr;
  type = GAMEOBJECT;
}