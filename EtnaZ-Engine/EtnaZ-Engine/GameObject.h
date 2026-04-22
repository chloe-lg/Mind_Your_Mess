#pragma once
#include "SFML/Graphics.hpp"
#include "Collider.h"


class Game;
class Player;

// Class for create an object
class GameObject {
protected:
    // Variable
    sf::Texture* tex;
    sf::Color color;

    sf::Vector2f pos;
    sf::Vector2f size;
    sf::Vector2f scale;

    sf::RectangleShape rect;
    bool visibility;

    // Object for manage collision
    Collider* collider;

public:
    // Constructor/Destructor
    GameObject() = default;
    GameObject(float x, float y);
    GameObject(float x, float y, float w, float h);
    virtual ~GameObject();

    virtual void onPlayerCollide(Game* game, Player* player) {}

    // Method get/set
    sf::Texture* getTexture();
    sf::Vector2f& getPos();
    sf::Vector2f& getSize();
    Collider* getCollider();

    void setCollider(Collider* collider);

    void setTexture(sf::Texture* tex);
    void setColor(sf::Color nColor);

    void setPos(sf::Vector2f nPos);
    void setSize(sf::Vector2f nSize);
    void setScale(sf::Vector2f scale);

    // Visibility
    void setVisibilityTrue();
    void setVisibilityFalse();

    // Method virtual
    virtual void update(float& dt);
    virtual void render();
};
