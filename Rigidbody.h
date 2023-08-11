#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "flagsapi.h"

/// Stores and provides the velocity of a GameObject

class Rigidbody {
public:
    Rigidbody();

    
    /// Speed is only accurate up to 2 decimals. Further decimals are truncated
    /// <returns></returns>
    float GetXSpeed();

    
    /// Speed is only accurate up to 2 decimals. Further decimals are truncated
    /// <returns></returns>
    float GetYSpeed();

    
    /// Speed is only accurate up to 2 decimals. Further decimals are truncated
    /// <returns></returns>
    void SetXSpeed(float speed);

    
    /// Speed is only accurate up to 2 decimals. Further decimals are truncated
    /// <returns></returns>
    void SetYSpeed(float speed);

private:
    uint16_t xSpeed; // 2 Bytes
    uint16_t ySpeed; // 2 Bytes
};

#endif