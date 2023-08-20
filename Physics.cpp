#include "Physics.h"

ResizingArray<GameObject*> Physics::physicsBodies = ResizingArray<GameObject*>(5);
ResizingArray<CollidableImage*> Physics::boundaries = ResizingArray<CollidableImage*>(5);

void Physics::Initialize() {
	//pairs.reserve(16);
	//physicsBodies.reserve(8);
	//boundaries.reserve(20);

  /*
	for (uint16_t i = 0; i < pairs.size(); i++) {
		pairs[i] = nullptr;
	}
  */
	for (uint16_t i = 0; i < physicsBodies.GetSize(); i++) {
		physicsBodies[i] = nullptr;
	}
	for (uint16_t i = 0; i < boundaries.GetSize(); i++) {
		boundaries[i] = nullptr;
	}
}

int Physics::TotalTakenSize() {
	return /*sizeof(pairs) +*/ sizeof(physicsBodies) + sizeof(boundaries);
}

/*
void Physics::AddPair(ContactPair pair) {
	pairs.push_back(&pair);
}

void Physics::RemovePair(ContactPair pair) {
	for (int i = 0; i < pairs.size(); i++) {
		if (pairs[i] == &pair) {
			pairs.erase(pairs.begin() + i);
		}
	}
}

void Physics::ClearPairs() {
	pairs.clear();
}
*/

void Physics::AddPhysicsBody(GameObject* physicsBody) {
	//std::cout << "Adding physics body\n";
	physicsBodies.Push(physicsBody);
}

void Physics::RemovePhysicsBody(GameObject* physicsBody) {
	for (int i = 0; i < physicsBodies.GetSize(); i++) {
		if (physicsBodies[i] == physicsBody) {
			physicsBodies.Remove(physicsBodies[i]);
		}
	}
}

void Physics::AddBoundary(CollidableImage* boundary) {
	boundaries.Push(boundary);
}

void Physics::RemoveBoundary(CollidableImage* boundary) {
	for (int i = 0; i < boundaries.GetSize(); i++) {
		if (boundaries[i] == boundary) {
			boundaries.Remove(boundaries[i]);
		}
	}
}


void Physics::ApplyPhysics() {
	// Starting from bottom to top for physics bodies, 
  // compare the bottom most physics body with the top most boundary
  // If the lowest object would hit any of the boundary objects, move it as far as it can

  // Maybe change to store only a single array of lowest tiered objects and check booleans
  // At the end of the day, it should be the lowest object moving down, then the one above it checking if
  // it would run into the ones below it. If at any point they would, stop them at the point of contact.

  // Do the same for objects moving to the right and objects moving to the left 
    
	// For all physics objects
	for (int i = 0; i < physicsBodies.GetSize(); i++) {
		//std::cout << "Body[" << i << "] y coordinate: " << physicsBodies[i]->GetY() << "\n";

		// For all boundaries
		for (int j = 0; j < boundaries.GetSize(); j++) {

		}

		/*
		for (int j = 0; j < boundaries.size(); j++) {

		}
		*/
	}
}