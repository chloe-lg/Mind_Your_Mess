#pragma once
#include "SFML/Graphics.hpp"
#include "TXAnimated.h"
#include "GameObject.h"

struct State {
    virtual  ~State() = default;
    virtual void update(float& dt, GameObject* owner) = 0;
    virtual void render() = 0;
    void setState(State* state);
    State* nextState = nullptr;
    TXAnimated* texAnimated = nullptr;
    sf::Texture* texture = nullptr;
};

struct StateMachine {
    State* currentState = nullptr;
    StateMachine(State* startState);
    virtual void update(float& dt, GameObject* owner);
    ~StateMachine();
};