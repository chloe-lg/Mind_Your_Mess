#include "Player.h"

Player::Player() : Player(0, 0, 50, 50) {

}

Player::Player(float x, float y) : Player(x, y, 50, 50) {

}

Player::Player(float x, float y, float w, float h) : GameObject(x, y, w, h) {
    speed = 400.0f;
    normalSpeed = 400.0f;
    slowTimer = 0.f;
    horizontalSpeed = 0.f;
    verticalSpeed = 0.f;
}

float Player::getSpeed() {
    return speed; 
}

float Player::getNormalSpeed() {
    return normalSpeed;
}

void Player::setSpeed(float nSpeed) {
    speed = nSpeed;
}

void Player::applySlow(float nSpeed, float nDuration) {
    speed = nSpeed;
    slowTimer = nDuration;
}

void Player::controllKeyboard(float& dt) {
    GameObject::update(dt);

    float inputX = 0.f;
    float inputY = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        inputY = -1.f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        inputY = 1.f;
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        inputX = -1.f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        inputX = 1.f;
    }

    float targetHorizontalSpeed = inputX * speed;
    horizontalSpeed += (targetHorizontalSpeed - horizontalSpeed) * 6.f * dt;

    if (inputX == 0.f && horizontalSpeed > -5.f && horizontalSpeed < 5.f) {
        horizontalSpeed = 0.f;
    }

    float targetVerticalSpeed = inputY * speed;
    verticalSpeed += (targetVerticalSpeed - verticalSpeed) * 7.f * dt;

    if (inputY == 0.f && verticalSpeed > -5.f && verticalSpeed < 5.f) {
        verticalSpeed = 0.f;
    }

    pos.x += horizontalSpeed * dt;
    pos.y += verticalSpeed * dt;

    if (pos.x < 0.f) {
        pos.x = 0.f;
    }
       
    if (pos.x + size.x > PLAYABLE_WIDTH){
        pos.x = PLAYABLE_WIDTH - size.x;
    }

    if (pos.y < 0.f)
    {
        pos.y = 0.f;
    }
    if (pos.y + size.y > LEVEL_HEIGHT)
    {
        pos.y = LEVEL_HEIGHT - size.y;
    }

    setPos(pos);
}

void Player::update(float& dt) {
    if (slowTimer > 0.f) {
        slowTimer -= dt;

        if (slowTimer <= 0.f) {
            speed = normalSpeed;
            slowTimer = 0.f;
        }
    }

    controllKeyboard(dt);
}

void Player::render() {
    GameObject::render();
}
