//#include <iostream>
#include "Image.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "GameObject.h"
#include "GameWorld.h"
#include "Physics.h"
#include "Input.h"
#include "Tinyfont.h"
#include "AbstractObject.h"
#include "Prefabs.h"
#include "MapEditor.h"
#include "Setup.h"
#include "ResizingArray.h"
#include <Arduboy2.h>


// Arduboy2 arduboy;
// Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());
Image objects[5];
int counter = 0;


void setup() {
  Setup::arduboy.begin();
  Setup::arduboy.clear();
  Setup::arduboy.setFrameRate(1);
  
  // put your setup code here, to run once:
  GameWorld::Initialize();

  MapEditor::CreateMap(MapEditor::map1, 0, 0);

  // for (int i = 0; i < 5; i++){
  //   objects[i] = NULL;
  // }

  /*
  GameObject* go1 = new GameObject();
  // go1->SetX(25);
  GameObject* go2 = new GameObject();
  // go2->SetX(19);
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
  */

  //GameWorld::PrintWorldObjects();

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

ResizingArray<int> intResizeArr(5);
bool nextFrame = false;

void loop() {
  if (!nextFrame){
    Setup::arduboy.pollButtons();
    if (Setup::arduboy.pressed(RIGHT_BUTTON)) nextFrame = true;
  }

  if(!(Setup::arduboy.nextFrame()) || !nextFrame) {
    return;
  }

  nextFrame = false;
  
  // put your main code here, to run repeatedly:
  Setup::arduboy.pollButtons();

  uint8_t pressedButtons = 0b00000000;

  if (Setup::arduboy.pressed(UP_BUTTON))
    pressedButtons |= 1 << 7;
  if (Setup::arduboy.pressed(DOWN_BUTTON))
    pressedButtons |= 1 << 6;
  if (Setup::arduboy.pressed(LEFT_BUTTON))
    pressedButtons |= 1 << 5;
  if (Setup::arduboy.pressed(RIGHT_BUTTON))
    pressedButtons |= 1 << 4;
  if (Setup::arduboy.pressed(B_BUTTON))
    pressedButtons |= 1 << 3;
  if (Setup::arduboy.pressed(A_BUTTON))
    pressedButtons |= 1 << 2;

  Input::UpdateKeys(pressedButtons);

  Setup::arduboy.clear();
  Setup::tinyfont.setCursor(0, 0);
    // we set our cursor 5 pixels to the right and 10 down from the top
  // (positions start at 0, 0)
  Setup::arduboy.setCursor(0, 0);

  // GameWorld::Initialize();

  // then we print to screen what is in the Quotation marks ""
  if (Input::GetKeyDown(Input::UP))
    Setup::tinyfont.print(F("UP WAS LET GO\n"));
  else if (Input::GetKeyUp(Input::UP))
    Setup::tinyfont.print(F("UP WAS PRESSED\n"));
  else if (Input::GetKey(Input::UP))
    Setup::tinyfont.print(F("UP IS BEING HELD DOWN\n"));

  // Collider col = Collider();
  // Image img = Image(); // 9 bytes -> can have 118 objects in memory AT MOST at one time
  // CollidableImage ci = CollidableImage(); // 13 bytes -> can have 118 objects in memory AT MOST at one time
  // GameObject go = GameObject(); // 17 bytes -> can have 90 total objects in memory AT MOST at one time
  uint8_t* imgPtr = nullptr;

  // int size = sizeof(go);
  // img.Update();

  if (counter < 29){
    intResizeArr.Push((counter+1) * 10);
    counter++;
  }

  // if (GameWorld::worldObjects.size() < 30)
  //   MapEditor::CreateMap(MapEditor::map1, 0, 0);

  // The Arduino Vector library is the world's crappiest resizing thing. You need to give it an area to store the data, but it has to already be a set size!
  // This means that you have to already be storing the space itself. Very silly and very dumb, as you're not actually saving any memory space.
  // Additionally, you can't use a pointer with no values. Pushing back does nothing to it.
  // Will either need to make a linked list class or my own resizing vector.
  // int* storage;
  // Vector<int> temp;
  // temp.setStorage(storage, 30, 5);
  // temp.push_back(5);

  Setup::tinyfont.print("Array size: ");
  Setup::tinyfont.print(intResizeArr.GetSize());
  Setup::tinyfont.print("\n");

  for (int i = 0; i < GameWorld::worldObjects.size(); i++){
    // if (GameWorld::worldObjects[i].GetX() != Image().GetX()){
      // GameWorld::worldObjects[i].SetX((i+1)*10);
    // }
    Setup::tinyfont.print("Object ");
    Setup::tinyfont.print(i);
    Setup::tinyfont.print("x: ");
    Setup::tinyfont.print(objects[i].GetX());
    Setup::tinyfont.print("\n");
  }

  for (int i = 0; i < intResizeArr.GetSize(); i++){
    if (i % intResizeArr.spacingAmount != 0) continue;
    Setup::tinyfont.print("Object ");
    Setup::tinyfont.print(i);
    Setup::tinyfont.print(" value: ");
    Setup::tinyfont.print(intResizeArr[i]);
    Setup::tinyfont.print("\n");
  }

  // float size = MapEditor::GetBrick()->GetX();

  // Setup::tinyfont.print(F("Img x position:"));
  // Setup::tinyfont.print(size);
  // Setup::tinyfont.print("\n");

  Setup::arduboy.display();
  return;
}