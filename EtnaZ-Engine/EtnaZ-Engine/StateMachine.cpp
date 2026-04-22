#include "StateMachine.h"

StateMachine::StateMachine(State* startState) : currentState(startState) {
}

void StateMachine::update(float& dt, GameObject* owner) {
    currentState->update(dt, owner);
    State* nextstate = currentState->nextState;
    if (nextstate != nullptr && nextstate != currentState) {
        delete currentState;
        currentState = nextstate;
        currentState->nextState = nullptr;
    }
}

StateMachine::~StateMachine() {
    delete currentState;
    currentState = nullptr;
}