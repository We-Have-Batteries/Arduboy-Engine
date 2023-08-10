#ifndef INPUT_H
#define INPUT_H

#include "flagsapi.h"

class Input {
public:
  enum Keys{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    PRIMARY,
    SECONDARY
  };

  static bool GetKey(Keys key);

  static bool GetKeyDown(Keys key);

  static bool GetKeyUp(Keys key);

  static void UpdateKeys(uint8_t keysPressed);

private:
  static uint8_t isPressed;
  static uint8_t pressedThisFrame;
  static uint8_t releasedThisFrame;
};

#endif