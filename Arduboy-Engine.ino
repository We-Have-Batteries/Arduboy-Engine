//#include <iostream>
#include "Image.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "GameObject.h"
#include "GameWorld.h"
//#include "ContactPair.h"
#include "Physics.h"
#include "Input.h"
#include "Tinyfont.h"
#include "AbstractObject.h"
#include "Prefabs.h"
#include <Arduboy2.h>


Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());


void setup() {
  arduboy.begin();
  arduboy.clear();
  arduboy.setFrameRate(1);

  CollidableImage img = CollidableImage();
  
  // put your setup code here, to run once:
  GameWorld::Initialize();
  GameObject* go1 = new GameObject();
  go1->SetX(25);
  GameObject* go2 = new GameObject();
  go2->SetX(19);
  GameObject go3 = GameObject();
  GameObject go4 = GameObject();
  GameObject go5 = GameObject();
  GameWorld::AddObject(go1);
  GameWorld::AddObject(go2);
  GameWorld::AddObject(&go3);
  GameWorld::AddObject(&go4);
  GameWorld::AddObject(&go5);

  go1->SetY(15);
  go2->SetY(25);
  go3.SetY(35);
  go4.SetY(45);
  go5.SetY(55);

  //GameWorld::PrintWorldObjects();
  
  for (int i = 0; i < GameWorld::worldObjects.size(); i++) {
      //std::cout << "Obj " << i << " location: " << GameWorld::worldObjects[i] << "\n";
  }
  

  Physics::ApplyPhysics();

  /*
  std::cout << "Size of Rigidbody: " << sizeof(Rigidbody) << "\n";
  std::cout << "Size of Collider: " << sizeof(Collider) << "\n";
  std::cout << "Size of LogicComponent: " << sizeof(LogicComponent) << "\n";
  std::cout << "Size of GameObject: " << sizeof(GameObject) << "\n";
  std::cout << "Size of CollidableImage: " << sizeof(CollidableImage) << "\n";
  std::cout << "Size of uint8_t: " << sizeof(uint8_t) << "\n";
  std::cout << "Size of ContactPair: " << sizeof(ContactPair) << "\n";
  std::cout << "Size of Physics: " << sizeof(Physics::TotalTakenSize()) << "\n";
  std::cout << "Size of an int: " << sizeof(int) << "\n";
  //std::cout << "IsOnScreen[0]: " << GameWorld::worldObjects[0]->IsOnScreen() << "\n";
  */
}

void loop() {

  if(!(arduboy.nextFrame())) {
    return;
  }
  
  // put your main code here, to run repeatedly:
  arduboy.pollButtons();

  uint8_t pressedButtons = 0b00000000;

  if (arduboy.pressed(UP_BUTTON))
    pressedButtons |= 1 << 7;
  if (arduboy.pressed(DOWN_BUTTON))
    pressedButtons |= 1 << 6;
  if (arduboy.pressed(LEFT_BUTTON))
    pressedButtons |= 1 << 5;
  if (arduboy.pressed(RIGHT_BUTTON))
    pressedButtons |= 1 << 4;
  if (arduboy.pressed(B_BUTTON))
    pressedButtons |= 1 << 3;
  if (arduboy.pressed(A_BUTTON))
    pressedButtons |= 1 << 2;

  Input::UpdateKeys(pressedButtons);

  arduboy.clear();
  tinyfont.setCursor(4, 9);
    // we set our cursor 5 pixels to the right and 10 down from the top
  // (positions start at 0, 0)
  arduboy.setCursor(4, 9);

  // then we print to screen what is in the Quotation marks ""
  if (Input::GetKeyDown(Input::UP))
    tinyfont.print(F("UP WAS LET GO\n"));
  else if (Input::GetKeyUp(Input::UP))
    tinyfont.print(F("UP WAS PRESSED\n"));
  else if (Input::GetKey(Input::UP))
    tinyfont.print(F("UP IS BEING HELD DOWN\n"));

  Collider col = Collider();
  Image img = Image(); // 9 bytes -> can have 118 objects in memory AT MOST at one time
  CollidableImage ci = CollidableImage(); // 13 bytes -> can have 118 objects in memory AT MOST at one time
  GameObject go = GameObject(); // 17 bytes -> can have 90 total objects in memory AT MOST at one time
  uint8_t* imgPtr = nullptr;

  int size = sizeof(go);
  img.Update();

  tinyfont.print(F("Img x position:\n"));
  tinyfont.print(size);

  arduboy.display();
  return;
}