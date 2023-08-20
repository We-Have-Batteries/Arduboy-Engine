#ifndef PHYSICS_H
#define PHYSICS_H

#include "GameObject.h"
#include "ResizingArray.h"

class Physics {
public:
	//static ResizingArrays<ContactPair*> pairs;
	static ResizingArray<GameObject*> physicsBodies;
	static ResizingArray<CollidableImage*> boundaries;

	static void Initialize();

	static int TotalTakenSize();

  /*
	static void AddPair(ContactPair pair);

	static void RemovePair(ContactPair pair);

	static void ClearPairs();
  */

	static void AddPhysicsBody(GameObject* physicsBody);

	static void RemovePhysicsBody(GameObject* physicsBody);

	static void AddBoundary(CollidableImage* boundary);

	static void RemoveBoundary(CollidableImage* boundary);

	static void ApplyPhysics();
};

#endif