#include "Input.h"

uint8_t Input::isPressed = 0b00000000;
uint8_t Input::pressedThisFrame = 0b00000000;
uint8_t Input::releasedThisFrame = 0b00000000;

void Input::UpdateKeys(uint8_t keysPressed){
  pressedThisFrame = isPressed & ~keysPressed;
  releasedThisFrame = ~isPressed & keysPressed; 
  isPressed = keysPressed;
}

bool Input::GetKey(Keys key){
  switch (key){
    case UP:
      return isPressed & 1 << 7;
    case DOWN:
      return isPressed & 1 << 6;
    case LEFT:
      return isPressed & 1 << 5;
    case RIGHT:
      return isPressed & 1 << 4;
    case PRIMARY:
      return isPressed & 1 << 3;
    case SECONDARY:
      return isPressed & 1 << 2;
  }
}

bool Input::GetKeyDown(Keys key){
  switch (key){
    case UP:
      return pressedThisFrame & 1 << 7;
    case DOWN:
      return pressedThisFrame & 1 << 6;
    case LEFT:
      return pressedThisFrame & 1 << 5;
    case RIGHT:
      return pressedThisFrame & 1 << 4;
    case PRIMARY:
      return pressedThisFrame & 1 << 3;
    case SECONDARY:
      return pressedThisFrame & 1 << 2;
  }
}

bool Input::GetKeyUp(Keys key){
  switch (key){
    case UP:
      return releasedThisFrame & 1 << 7;
    case DOWN:
      return releasedThisFrame & 1 << 6;
    case LEFT:
      return releasedThisFrame & 1 << 5;
    case RIGHT:
      return releasedThisFrame & 1 << 4;
    case PRIMARY:
      return releasedThisFrame & 1 << 3;
    case SECONDARY:
      return releasedThisFrame & 1 << 2;
  }
}