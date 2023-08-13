#include "Setup.h"

Tinyfont Setup::tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

uintptr_t Setup::PtrToInt(void* ptr){
  return reinterpret_cast<uintptr_t>(ptr);
}

int Setup::FreeMemory(int maxMemory){
  byte* buf;
  while ((buf = (byte*) malloc(--maxMemory)) == NULL);
  free(buf);
  return maxMemory;
}