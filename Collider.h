#ifndef COLLIDER_H
#define COLLIDER_H

//#include <cstdint>
#include "flagsapi.h"

/// Stores the width and height of an object, as well as their offset from the object's position
// Total size: 4 bytes
class Collider {
public:
    uint8_t width; // 1 Byte
    uint8_t height; // 1 Byte
    int8_t xOffset; // 1 Byte
    int8_t yOffset; // 1 Byte

    Collider();

    Collider(uint8_t width, uint8_t height, int8_t xOffset, int8_t yOffset);
};

#endif