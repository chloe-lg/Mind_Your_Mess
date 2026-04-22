#include "Soy.h"
#include "Player.h"


Soy::Soy() : Soy(0, 0, 50, 50) {

}

Soy::Soy(float x, float y) : Soy(x, y, 50, 50) {
}

Soy::Soy(float x, float y, float w, float h) : GameObject(x, y, w, h) {
    setCollider(new Collider(this));
}


void Soy::onPlayerCollide(Game* game, Player* player)
{
    player->applySlow(150.f, 2.f);
}

void Soy::update(float& dt) {
}

void Soy::render() {
    GameObject::render();
}
