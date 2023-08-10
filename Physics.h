#ifndef PHYSICS_H
#define PHYSICS_H

//#include "ContactPair.h"
//#include "TickContact.h"
#include "GameObject.h"
#include <Vector.h>

class Physics {
public:
	//static Vector<ContactPair*> pairs;
	static Vector<GameObject*> physicsBodies;
	static Vector<CollidableImage*> boundaries;

	static void Initialize();

	static int TotalTakenSize();

  /*
	static void AddPair(ContactPair pair);

	static void RemovePair(ContactPair pair);

	static void ClearPairs();
  */

	static void AddPhysicsBody(GameObject* physicsBody);

	static void RemovePhysicsBody(GameObject physicsBody);

	static void AddBoundary(CollidableImage boundary);

	static void RemoveBoundaries(CollidableImage boundary);

	static void ApplyPhysics();
};

#endif