#ifndef IMAGE_H
#define IMAGE_H

#include "flagsapi.h"
#include "Input.h"
class CollidableImage;

class Image{
public:
  uint8_t* image;

  /// Available flags:
  /// IsActive
  /// Trigger
  /// Kinematic -> Kinematic means to be able to receive force. Will still travel according to rigidbody speed
  /// ReceivesGravity
  /// NONE
  /// NONE
  /// 17th bit for x: is it positive (1) or negative (0)
  /// 17th bit for y: is it positive (1) or negative (0)
  uint8_t flags;

  Image();

  Image(uint8_t* img, float x, float y);
  
  /// Position is only accurate up to 2 decimals. Further decimals are truncated
  float GetX();
  
  /// Position is only accurate up to 2 decimals. Further decimals are truncated
  float GetY();
  
  /// Position is only accurate up to 2 decimals. Further decimals are truncated
  void SetX(float position);
  
  /// Position is only accurate up to 2 decimals. Further decimals are truncated
  void SetY(float position);
    
  /// Called at the start of the object's instantiation
  virtual void Start();
  
  /// Called before every frame render
  virtual void Update();
  
  /// Called before every physics update
  virtual void FixedUpdate();
  
  /// Called the first time other enters this object's trigger (resets when that object leaves the trigger)
  virtual void OnTriggerEnter(CollidableImage other);
  
  /// Called after the physics tick determines that an object has something inside of its trigger
  virtual void OnTrigger(CollidableImage Other);
  
  /// Called the first time other collides with this object's collider (resets when that object stops touching this object)
  virtual void OnCollisionEnter(CollidableImage other);

  /// Called after the physics tick determines that an object has collided with something
  virtual void OnCollision(CollidableImage other);

protected:
  uint16_t x;
  uint16_t y;
};

#endif