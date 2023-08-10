#include "CollidableImage.h"

CollidableImage::CollidableImage() : Image() {
    col = Collider();
}

CollidableImage::CollidableImage(float x, float y, uint8_t flags, Collider col, uint8_t* imgPtr) : Image(imgPtr, x, y) {
    this->col = col;
    this->image = imgPtr;
    SetX(x);
    SetY(y);
    this->flags = flags;
}

bool CollidableImage::IsOnScreen() {
    return false;//std::abs(GameWorld::GetWorldX() + GetX()) < GameWorld::worldWidth + col.width && std::abs(GameWorld::GetWorldY() + GetY()) < GameWorld::worldHeight + col.height;
}

bool CollidableImage::IsActive() {
    return flags & (1 << 7);
}

bool CollidableImage::IsTrigger() {
    return flags & (1 << 6);
}

bool CollidableImage::IsKinematic() {
    return flags & (1 << 5);
}

bool CollidableImage::ReceivesGravity() {
    return flags & (1 << 4);
}

bool CollidableImage::BelowObject(CollidableImage* obj1, CollidableImage* obj2) {
    return obj1->GetY() > obj2->GetY();
}

bool CollidableImage::RightOfObject(CollidableImage* obj1, CollidableImage* obj2) {
    return obj1->GetX() > obj2->GetX();
}