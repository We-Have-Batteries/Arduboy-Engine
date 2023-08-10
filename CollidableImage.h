#ifndef COLLIDABLEIMAGE_H
#define COLLIDABLEIMAGE_H

#include "Collider.h"
#include "Image.h"

class CollidableImage : public Image {
public:
  Collider col; // 4 bytes

  CollidableImage();

  CollidableImage(float x, float y, uint8_t flags, Collider col, uint8_t* imgPtr);

  bool IsOnScreen();

  bool IsActive();

  bool IsTrigger();

  bool IsKinematic();

  bool ReceivesGravity();

  /// Returns whether obj1 is below obj2. Reminder: positive y is down
  static bool BelowObject(CollidableImage* obj1, CollidableImage* obj2);

  /// Returns whether obj1 is to the right of obj2
  static bool RightOfObject(CollidableImage* obj1, CollidableImage* obj2);
};

#endif