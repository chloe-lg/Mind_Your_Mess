#pragma once
#include "SFML/Graphics.hpp"

class TXAnimated {
private:
    int totalFrame;
    int currentFrame;

    float frameRate;

    sf::Vector2i framePos;
    sf::Vector2i frameSize;

    sf::IntRect spriteRect;
    sf::Texture* texture;
    sf::RectangleShape rect;

    const char* path;

    sf::Clock clock;
    float startPoint;
    float timer;
    float timeElapsed;

public:
    TXAnimated();
    ~TXAnimated() = default;

    void load(const char* path, float posX, float posY, float sizeX, float sizeY);

    void update(float& dt);
    void render();
};