#include "Collider.h"

Collider::Collider() {
    width = 0;
    height = 0;
    xOffset = 0;
    yOffset = 0;
}

Collider::Collider(uint8_t width, uint8_t height, int8_t xOffset, int8_t yOffset) {
    this->width = width;
    this->height = height;
    this->xOffset = xOffset;
    this->yOffset = yOffset;
}