#include "Collider.h"
#include "GameObject.h"

Collider::Collider(GameObject* _owner) {
    owner = _owner;
    collidable = true;
}

sf::RectangleShape& Collider::getBoxCollider() {
    return rect;
}

void Collider::setBoxColliderPos(sf::Vector2f nBoxPos) {

}

void Collider::setBoxColliderSize(sf::Vector2f nBoxSize) {
    rect.setSize(nBoxSize);
}

bool Collider::isCollidable() {
    return collidable;
}

bool Collider::isColliding(GameObject* target) {
    if (owner->getPos().x < target->getPos().x + target->getSize().x &&
        owner->getPos().x + owner->getSize().x > target->getPos().x &&
        owner->getPos().y < target->getPos().y + target->getSize().y &&
        owner->getPos().y + owner->getSize().y > target->getPos().y) {
        return true;
    }
    return false;
}

void Collider::resolveCollision(GameObject* target) {
    sf::Vector2f ownerPos = owner->getPos();
    sf::Vector2f ownerSize = owner->getSize();
    sf::Vector2f targPos = target->getPos();
    sf::Vector2f targSize = target->getSize();

    // Calcul des pénétration sur chaque axe
    float overlapLeft = (ownerPos.x + ownerSize.x) - targPos.x;
    float overlapRight = (targPos.x + targSize.x) - ownerPos.x;
    float overlapTop = (ownerPos.y + ownerSize.y) - targPos.y;
    float overlapBottom = (targPos.y + targSize.y) - ownerPos.y;

    // On choisit la pénétration minimale = côté le plus proche
    bool fromLeft = overlapLeft < overlapRight;
    bool fromTop = overlapTop < overlapBottom;

    float minOverlapX;
    if (fromLeft) {
        minOverlapX = overlapLeft;
    }
    else {
        minOverlapX = overlapRight;
    }

    float minOverlapY;
    if (fromTop) {
        minOverlapY = overlapTop;
    }
    else {
        minOverlapY = overlapBottom;
    }

    if (minOverlapX < minOverlapY) {
        if (fromLeft) {
            owner->setPos({ targPos.x - ownerSize.x, ownerPos.y }); // collision côté droit
        }
        else {
            owner->setPos({ targPos.x + targSize.x, ownerPos.y });  // collision côté gauche
        }
    }
    else {
        if (fromTop) {
            owner->setPos({ ownerPos.x, targPos.y - ownerSize.y }); // collision par le bas
        }
        else {
            owner->setPos({ ownerPos.x, targPos.y + targSize.y });  // collision par le haut
        }
    }
}

void Collider::updateCollider(GameObject* target) {
    isColliding(target);
}