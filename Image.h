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
  /// PhysicsEnabled
  /// NONE
  /// NONE
  /// NONE
  uint8_t flags;
  /// Available values:
  /// 17th bit for x: is it positive (1) or negative (0)
  /// 17th bit for y: is it positive (1) or negative (0)
  /// 17th bit for xSpeed: is it positive (1) or negative (0)
  /// 17th bit for ySpeed: is it positive (1) or negative (0)
  /// NONE
  /// NONE
  /// NONE
  /// NONE
  uint8_t signStorage;

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

  bool IsActive(){
    return flags & 1 << 7;
  }

  bool IsTrigger(){
    return flags & 1 << 6;
  }

  bool IsKinematic() { 
    return flags & 1 << 5;
  }

  bool ReceivesGravity(){
    return flags & 1 << 4;
  }

  bool PhysicsEnabled(){
    return flags & 1 << 3;
  }

  bool IsMovingRight(){
    return signStorage & 1 << 5;
  }

  bool IsMovingLeft(){
    return !(signStorage & 1 << 5);
  }

  bool IsMovingUp(){
    return !(signStorage & 1 << 4);
  }

  bool IsMovingDown(){
    return signStorage & 1 << 4;
  }
    
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

  virtual void SetVelocity(float xSpeed, float ySpeed);
  virtual void SetXSpeed(float xSpeed);
  virtual void SetYSpeed(float ySpeed);

protected:
  uint16_t x;
  uint16_t y;
};

#endif