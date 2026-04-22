#include "Knife.h"
#include "Player.h"


Knife::Knife() : Knife(0, 0, 50, 50) {

}

Knife::Knife(float x, float y) : Knife(x, y, 50, 50) {

}

Knife::Knife(float x, float y, float w, float h) : GameObject(x, y, w, h) {
    speed = 400.0f;
    startPos = { x, y };
    jabTimer = 0.f;
    jabDistance = 40.f;
    faceRight = x < PLAYABLE_WIDTH / 2.f;
    setCollider(new Collider(this));
    setFacingRight(faceRight);
}

void Knife::onPlayerCollide(Game* game, Player* player) {
    game->gameOver();
}

float Knife::getSpeed() {
    return speed;
}

bool Knife::isFacingRight() {
    return faceRight;
}

void Knife::setSpeed(float nSpeed) {
    speed = nSpeed;
}

void Knife::setFacingRight(bool nFaceRight) {
    faceRight = nFaceRight;

    if (faceRight) {
        rect.setOrigin({ size.x, 0.f });
        rect.setScale({ -1.f, 1.f });
    }
    else {
        rect.setOrigin({ 0.f, 0.f });
        rect.setScale({ 1.f, 1.f });
    }
}

void Knife::update(float& dt) {
    jabTimer += dt;

    if (jabTimer >= 3.f) {
        jabTimer = 0.f;
    }

    float offsetX = 0.f;
    float jabMoveTime = 0.2f;
    float jabReturnTime = 0.2f;

    if (jabTimer < jabMoveTime) {
        offsetX = jabDistance * (jabTimer / jabMoveTime);
    }
    else if (jabTimer < jabMoveTime + jabReturnTime) {
        float returnTimer = jabTimer - jabMoveTime;
        offsetX = jabDistance * (1.f - (returnTimer / jabReturnTime));
    }

    if (!faceRight) {
        offsetX = -offsetX;
    }

    setPos({ startPos.x + offsetX, startPos.y });
}

void Knife::render() {
    GameObject::render();
}
