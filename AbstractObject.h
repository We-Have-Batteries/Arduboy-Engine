#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

class Image;
class CollidableImage;
class GameObject;

class AbstractObject{
public:
  enum ObjectTypes{
    INVALID,
    IMAGE,
    COLLIDABLEIMAGE,
    GAMEOBJECT
  };

  void* objectPtr;
  ObjectTypes type;

  AbstractObject();

  AbstractObject(void* objPtr, ObjectTypes type);

  AbstractObject(Image* objPtr);

  AbstractObject(CollidableImage* objPtr);

  AbstractObject(GameObject* objPtr);
};

#endif