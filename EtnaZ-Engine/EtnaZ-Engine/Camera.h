#pragma once
#include "Globals.h"
#include "SFML/Graphics.hpp"
#include "GameObject.h"

class Camera {
public:
    GameObject* target;

private:
    sf::View view;
    float cameraY;
    float scrollSpeed;


public:
    Camera() = default;
    Camera(float scrollSpeed);
    ~Camera() = default;

    void update(float dt);
    bool isCaught(GameObject* myObject);

    sf::View& getView();

};
