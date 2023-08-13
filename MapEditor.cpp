#include "MapEditor.h"
#include "AbstractObject.h"
#include "GameObject.h"
#include "Setup.h"
#include "GameWorld.h"

const MapEditor::MethodType MapEditor::prefabMethods[4] = { Prefabs::Air, Prefabs::Brick, Prefabs::Player, Prefabs::Img };

const uint8_t MapEditor::map1[6] = { 
  2, 2, 
  2, 1,
  2, 1,
};

void MapEditor::CreateMap(uint8_t* map, float xOffset, float yOffset){
  // for the width times the height
  float xPos = xOffset;
  float yPos = yOffset;

  // Setup::tinyfont.print(F("CreatingMap: "));

  // Ignore the first two numbers, as that's our width and height of the map
  for (int i = 2; i < map[0] * map[1] + 2; i++){
    // if we hit the width, go down by one on the Y and reset the x back to 0
    if (i % map[0] == 0){
      yPos += gameWorldHeightPadding;
      xPos = xOffset;
    }
    AbstractObject obj = MapEditor::prefabMethods[map[i]]();
    static_cast<Image*>(obj.objectPtr)->SetX(xPos);
    static_cast<Image*>(obj.objectPtr)->SetY(yPos);
    switch(obj.type){
      case AbstractObject::IMAGE:
        GameWorld::AddObject(static_cast<Image*>(obj.objectPtr));
        break;
      case AbstractObject::COLLIDABLEIMAGE:
        GameWorld::AddObject(static_cast<CollidableImage*>(obj.objectPtr));
        break;
      case AbstractObject::GAMEOBJECT:
        GameWorld::AddObject(static_cast<GameObject*>(obj.objectPtr));
        break;
    }
    xPos += gameWorldWidthPadding;
  }
}

