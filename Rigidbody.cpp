#include "Rigidbody.h"


Rigidbody::Rigidbody() {
    xSpeed = 0;
    ySpeed = 0;
}

/// Speed is only accurate up to 2 decimals. Further decimals are truncated
/// <returns></returns>
float Rigidbody::GetXSpeed() {
    return (float)xSpeed / 100.0f;
}

/// Speed is only accurate up to 2 decimals. Further decimals are truncated
/// <returns></returns>
float Rigidbody::GetYSpeed() {
    return (float)ySpeed / 100.0f;
}

/// Speed is only accurate up to 2 decimals. Further decimals are truncated
/// <returns></returns>
void Rigidbody::SetXSpeed(float speed) {
    xSpeed = (short)speed * 100;
}

/// Speed is only accurate up to 2 decimals. Further decimals are truncated
/// <returns></returns>
void Rigidbody::SetYSpeed(float speed) {
    ySpeed = (short)speed * 100;
}