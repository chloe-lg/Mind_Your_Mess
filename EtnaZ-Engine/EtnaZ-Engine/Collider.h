#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

class GameObject;

class Collider {
private:
	sf::RectangleShape rect;
	GameObject* owner;
	bool collidable;

public:
	Collider(GameObject* owner);
	~Collider() = default;

	sf::RectangleShape& getBoxCollider();
	void setBoxColliderPos(sf::Vector2f nBoxPos);
	void setBoxColliderSize(sf::Vector2f nBoxSize);

	bool isCollidable();
	bool isColliding(GameObject* target);
	void resolveCollision(GameObject* target);

	void updateCollider(GameObject* target);
};