#pragma once
#include "Game.h"

class Soy : public GameObject {
private:

public:
    Soy();
    Soy(float x, float y);
    Soy(float x, float y, float w, float h);
    virtual ~Soy() override = default;

 
	virtual void onPlayerCollide(Game* game, Player* player) override;

    virtual void update(float& dt) override;
    virtual void render() override;

};