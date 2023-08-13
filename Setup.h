#ifndef SETUP_H
#define SETUP_H

#include "Tinyfont.h"
#include <Arduboy2.h>

class Setup{
public:
  static Arduboy2 arduboy;
  static Tinyfont tinyfont;
  static uintptr_t PtrToInt(void* ptr);
  static int FreeMemory(int maxMemory);
};

#endif