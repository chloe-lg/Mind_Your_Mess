#include "Finish.h"

Finish::Finish() : Finish(0, 0, 50, 50) {

}

Finish::Finish(float x, float y) : Finish(x, y, 50, 50) {

}

Finish::Finish(float x, float y, float w, float h) : GameObject(x, y, w, h) {
    setCollider(new Collider(this));
}

void Finish::onPlayerCollide(Game* game, Player* player) {
    game->win();
}

void Finish::render() {
}
