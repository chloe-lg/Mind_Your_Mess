#include "GameState.h"
#include "GameEngine.h"

// Function which pop the current scene f or put the other after
// ######
void GameState::nextState() {
    if (!GameEngine::activeStates.empty()) {
        GameEngine::activeStates.pop_back();
    }
}
// ######

// Function for pause a scene
// ######
void GameState::pause() {
    if (!GameEngine::activeStates.empty()) {
        GameEngine::states.push_back(GameEngine::activeStates.back());
        GameEngine::activeStates.pop_back();
    }
}
// ######

// Function for resume a scene
// ######
void GameState::resume() {
    if (!GameEngine::activeStates.empty() && !GameEngine::states.empty()) {
        GameEngine::activeStates.pop_back();
        GameEngine::activeStates.push_back(GameEngine::states.back());
        GameEngine::states.pop_back();
    }
}
// ######
