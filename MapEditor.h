#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "flagsapi.h"
#include "Prefabs.h"
#include "GameWorld.h"

class AbstractObject;
class CollidableImage;

class MapEditor{
public:
  using MethodType = AbstractObject(*)();

  static const int gameWorldWidthPadding = 4;
  static const int gameWorldHeightPadding = 4;

  static const uint8_t map1[6];

  static const MethodType prefabMethods[4];

  static CollidableImage* GetBrick(){
    return static_cast<CollidableImage*> (prefabMethods[1]().objectPtr);
  }

  static void CreateMap(uint8_t* map, float xOffset = 0, float yOffset = 0);
};

#endif