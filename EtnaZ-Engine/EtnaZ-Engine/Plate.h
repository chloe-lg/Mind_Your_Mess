#pragma once
#include "Game.h"

class Plate : public GameObject {
private:
    
public:
    Plate();
    Plate(float x, float y);
    Plate(float x, float y, float w, float h);
    virtual ~Plate() override = default;

	virtual void onPlayerCollide(Game* game, Player* player) override;

    virtual void render() override;

};