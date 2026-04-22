#pragma once
#include "GameObject.h"
#include "Globals.h"

class Player : public GameObject {
private:
    float speed;
    float normalSpeed;
    float slowTimer;
    float horizontalSpeed;
    float verticalSpeed;
public:
    Player();
    Player(float x, float y);
    Player(float x, float y, float w, float h);
    virtual ~Player() override = default;

    float getSpeed();
    float getNormalSpeed();

    void setSpeed(float nSpeed);
    void applySlow(float nSpeed, float nDuration);

    void controllKeyboard(float& dt);

    virtual void update(float& dt) override;
    virtual void render() override;

}; 
