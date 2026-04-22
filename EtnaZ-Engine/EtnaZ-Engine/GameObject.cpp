#include "GameObject.h"

#include "GameEngine.h"


// Constructor
// ####
GameObject::GameObject(float x, float y) : GameObject(x, y, 50, 50) {

}

GameObject::GameObject(float x, float y, float w, float h) : pos({ x,y }), size({ w,h }), visibility(true), tex(nullptr), scale({ 1,1 }) {
    color = sf::Color::White;
    rect.setFillColor(color);
    rect.setPosition(pos);
    rect.setSize(size);
    rect.setScale(scale);

    collider = nullptr;
}
// #####

GameObject::~GameObject() {
    delete collider;
    collider = nullptr;
}


// Get variable
// #####
sf::Texture* GameObject::getTexture() {
    return tex;
}

sf::Vector2f& GameObject::getPos() {
    return pos;
}

sf::Vector2f& GameObject::getSize() {
    return size;
}

Collider* GameObject::getCollider() {
    return collider;
}

void GameObject::setCollider(Collider* _collider) {
    collider = _collider;
}

// #####


// Set variable
// #####
void GameObject::setTexture(sf::Texture* nTex) {
    tex = nTex;
}

void GameObject::setColor(sf::Color nColor) {
    rect.setFillColor(nColor);
}

void GameObject::setPos(sf::Vector2f nPos) {
    pos = nPos;
    rect.setPosition(nPos);
}

void GameObject::setSize(sf::Vector2f nSize) {
    size = nSize;
    rect.setSize(nSize);
}

void GameObject::setScale(sf::Vector2f nScale) {
    scale = nScale;
    rect.setScale(nScale);
}
// #####


// Set visibility
// #####
void GameObject::setVisibilityTrue() {
    visibility = true;
}

void GameObject::setVisibilityFalse() {
    visibility = false;
}

// #####


// Virtual method
// #####
void GameObject::update(float& dt) {

}

void GameObject::render() {
    if (visibility) {
        if (tex) {
            rect.setTexture(tex);
        }
        GameEngine::window->draw(rect);
    }
}
// #####
