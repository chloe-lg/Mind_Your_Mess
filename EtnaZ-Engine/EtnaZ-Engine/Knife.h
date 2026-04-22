#pragma once
#include "Game.h"

class Knife : public GameObject {
private:
    float speed;
    sf::Vector2f startPos;
    float jabTimer;
    float jabDistance;
    bool faceRight;
public:
    Knife();
    Knife(float x, float y);
    Knife(float x, float y, float w, float h);
    virtual ~Knife() override = default;

	virtual void onPlayerCollide(Game* game, Player* player) override;

    float getSpeed();
    bool isFacingRight();

    void setSpeed(float nSpeed);
    void setFacingRight(bool nFaceRight);


    virtual void update(float& dt) override;
    virtual void render() override;

};
