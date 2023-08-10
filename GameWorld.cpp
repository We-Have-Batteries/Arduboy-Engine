#include "GameWorld.h"
#include <Vector.h>

short GameWorld::worldX = 0;
short GameWorld::worldY = 0;
Vector<GameObject*> GameWorld::worldObjects;

float GameWorld::GetWorldX() {
    return (float)worldX / 100.0f;
}

float GameWorld::GetWorldY() {
    return (float)worldY / 100.0f;
}

void GameWorld::SetWorldX(float position) {
    if (position > 327.67f) position = 327.67;
    else if (position < -327.67f) position = -327.67;
    worldX = (short)position * 100;
}

void GameWorld::SetWorldY(float position) {
    if (position > 327.67f) position = 327.67;
    else if (position < -327.67f) position = -327.67;
    worldY = (short)position * 100;
}

void GameWorld::Initialize() {
    //std::cout << "Initializing GameWorld\n";
    worldObjects.begin();
    SetWorldX(0);
    SetWorldY(0);

    Physics::Initialize();
}

void GameWorld::AddObject(GameObject* newObject) {
    //std::cout << "Adding new object to worldObjects\n";
    newObject->Start();
    worldObjects.push_back(newObject);
    Physics::AddPhysicsBody(newObject);
}

void GameWorld::PrintWorldObjects() {
    for (int i = 0; i < worldObjects.size(); i++) {
        //std::cout << "Object " << i << "\n";
    }
}

void GameWorld::UpdateSequence() {
    for (int i = 0; i < worldObjects.size(); i++) {
        worldObjects[i]->Update();
    }
    // Display method here
}

/// Runs all object's fixed update, then runs the physics tick
void GameWorld::FixedUpdateSequence() {
    // Apply each object's fixed update before applying physics. Lets values change before running the physics
    for (int i = 0; i < worldObjects.size(); i++) {
        worldObjects[i]->FixedUpdate();
    }
    Physics::ApplyPhysics();
}