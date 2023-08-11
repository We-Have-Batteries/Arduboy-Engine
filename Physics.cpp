#include "Physics.h"

Vector<GameObject*> Physics::physicsBodies;
Vector<CollidableImage*> Physics::boundaries;

void Physics::Initialize() {
	//pairs.reserve(16);
	//physicsBodies.reserve(8);
	//boundaries.reserve(20);

  /*
	for (uint16_t i = 0; i < pairs.size(); i++) {
		pairs[i] = nullptr;
	}
  */
	for (uint16_t i = 0; i < physicsBodies.size(); i++) {
		physicsBodies[i] = nullptr;
	}
	for (uint16_t i = 0; i < boundaries.size(); i++) {
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
	physicsBodies.push_back(physicsBody);
}

void Physics::RemovePhysicsBody(GameObject physicsBody) {
	for (int i = 0; i < physicsBodies.size(); i++) {
		if (physicsBodies[i] == &physicsBody) {
			physicsBodies.remove(i);
		}
	}
}

void Physics::AddBoundary(CollidableImage* boundary) {
	boundaries.push_back(boundary);
}

void Physics::RemoveBoundaries(CollidableImage boundary) {
	for (int i = 0; i < boundaries.size(); i++) {
		if (boundaries[i] == &boundary) {
			boundaries.remove(i);
		}
	}
}


void Physics::ApplyPhysics() {
	// Sorts the physics bodies based on who is below who
	//if (physicsBodies.size() > 1)
		//std::sort(physicsBodies.begin(), physicsBodies.end(), GameObject::BelowObject);
    //ace_sorting::shellSortKnuth(physicsBodies, physicsBodies.size(), [](GameObject* a, GameObject* b) { return a->GetY() > b->GetY(); });
  // Sorts the boundaries based on who is below who
	//if (boundaries.size() > 1)
		//std::sort(boundaries.begin(), boundaries.end(), GameObject::BelowObject);
    //ace_sorting::shellSortKnuth(physicsBodies, physicsBodies.size(), GameObject::BelowObject);

  //Sort arrays here
    
	// For all physics objects
	for (int i = 0; i < physicsBodies.size(); i++) {
		//std::cout << "Body[" << i << "] y coordinate: " << physicsBodies[i]->GetY() << "\n";

		// For all boundaries
		for (int j = 0; j < boundaries.size(); j++) {

		}

		/*
		for (int j = 0; j < boundaries.size(); j++) {

		}
		*/
	}
}