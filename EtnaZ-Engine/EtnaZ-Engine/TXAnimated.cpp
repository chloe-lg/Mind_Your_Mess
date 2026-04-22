#include "TXAnimated.h"

#include "GameEngine.h"

TXAnimated::TXAnimated() : framePos({ 0,0 }), currentFrame((0)), startPoint(0) {
}

void TXAnimated::load(const char* _path, float posX, float posY, float sizeX, float sizeY) {
    path = _path;

    totalFrame -= 1;

    spriteRect = sf::IntRect({ 0, 0 }, { frameSize });

    if (texture->loadFromFile(path)) {}
    frameSize = { static_cast<int>(sizeX), static_cast<int>(sizeY) };

    rect.setSize({ sizeX, sizeY });
    rect.setPosition({ posX, posY });
    rect.setTexture(texture);
    rect.setTextureRect(spriteRect);
}

void TXAnimated::update(float& dt) {
    timeElapsed = clock.getElapsedTime().asMilliseconds();
    startPoint += dt;

    if (startPoint >= frameRate) {
        framePos.x += frameSize.x;
        spriteRect = sf::IntRect({ framePos.x, 0 }, { frameSize.x, frameSize.y });

        currentFrame += 1;
        rect.setTextureRect(spriteRect);

        startPoint = 0;
    }

    if (currentFrame == totalFrame) {
        currentFrame = 0;
        framePos.x = 0;
        framePos.y = 0;
    }

    clock.reset();
}

void TXAnimated::render() {
    GameEngine::window->draw(rect);
}