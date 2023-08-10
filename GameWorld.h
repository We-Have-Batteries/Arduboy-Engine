#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "Physics.h"
#include <Vector.h>


/// References all the objects available in the game world and runs their methods accordingly

class GameWorld {
public:
    static Vector<GameObject*> worldObjects;
    const static short worldWidth = 128;
    const static short worldHeight = 64;

    static float GetWorldX();
    static float GetWorldY();
    static void SetWorldX(float position);
    static void SetWorldY(float position);

    static void Initialize();

    static void AddObject(GameObject* newObject);

    static void PrintWorldObjects();

    static void UpdateSequence();

    static void FixedUpdateSequence();

private:
    static short worldX;
    static short worldY;
    static float biggerWorldX;
    static float biggerWorldY;
};

#endif