#pragma once
#include "Game.h"

class Finish : public GameObject {
public:
    Finish();
    Finish(float x, float y);
    Finish(float x, float y, float w, float h);
    virtual ~Finish() override = default;

    virtual void onPlayerCollide(Game* game, Player* player) override;
    virtual void render() override;
};
