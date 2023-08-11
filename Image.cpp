#include "Image.h"
#include "CollidableImage.h"
#include "Setup.h"

Image::Image(){
  image = nullptr;
  flags = 0b11100000;
  SetX(0);
  SetY(0);
}

/// Available flags:
/// IsActive
/// Trigger
/// Kinematic -> Kinematic means to be able to receive force. Will still travel according to rigidbody speed
/// ReceivesGravity
/// NONE
/// NONE
/// 17th bit for x: is it positive (1) or negative (0)
/// 17th bit for y: is it positive (1) or negative (0)
Image::Image(uint8_t* img, float x, float y){
  image = img;
  flags = 0b00000000;
  // Sets it to active
  flags |= 1 << 7;
  // Sets it to not collide with environment
  flags |= 1 << 6;
  // Sets it to not receive force
  flags |= 1 << 5;
  // Doesn't receive gravity automatically

  // Sets the x and y positions, also handles the last two bits
  SetX(x);
  SetY(y);
}

/// Position is only accurate up to 2 decimals. Further decimals are truncated
float Image::GetX() {
  // If it's a positive x, return it casted plus the decimal
  if (flags & 1 << 1) return (float)x / 100.0f;
  // If it's a negative x, return it casted plus decimal times -1
  else return -1 * float(x) / 100.0f;
}

/// Position is only accurate up to 2 decimals. Further decimals are truncated
float Image::GetY() {
  // If it's a positive x, return it casted plus the decimal
  if (flags & 1 << 0) return (float)y / 100.0f;
  // If it's a negative x, return it casted plus decimal times -1
  else return -1 * float(y) / 100.0f;
}

/// Position is only accurate up to 2 decimals. Further decimals are truncated. Max value is 655.35
void Image::SetX(float position) {
  if (position > 655.35f) position = 655.35f;
  else if (position < -655.35f) position = -655.35f;
  if (position < 0) {
      position *= -1;
      // Sets the x to be negative
      flags &= ~(1 << 1);
  }
  else {
      // Sets the x to be positive
      flags |= 1 << 1;
  }
  x = (int)(position * 100);
}

/// Position is only accurate up to 2 decimals. Further decimals are truncated. Max value is 655.35
void Image::SetY(float position) {
  if (position > 655.35f) position = 655.35f;
  else if (position < -655.35f) position = -655.35f;
  if (position < 0) {
      position *= -1;
      // Sets the y to be negative
      flags &= ~(1 << 0);
  }
  else {
      // Sets the y to be positive
      flags |= 1 << 0;
  }
  y = (int)(position * 100);
}

void Image::Start(){
  Setup::tinyfont.print("Image is starting\n");
}

void Image::Update(){
  if (Input::GetKey(Input::UP)){
    SetX(GetX()+1);
  }
}

void Image::FixedUpdate(){}

void Image::OnTriggerEnter(CollidableImage other){}

void Image::OnTrigger(CollidableImage Other){}

void Image::OnCollisionEnter(CollidableImage other){}

void Image::OnCollision(CollidableImage other){}