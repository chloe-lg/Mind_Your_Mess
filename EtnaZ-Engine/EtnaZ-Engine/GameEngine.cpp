#include "GameEngine.h"

// Initialise static
// #####
sf::RenderWindow* GameEngine::window = nullptr;
std::vector<GameState*> GameEngine::states;
std::vector<GameState*> GameEngine::activeStates;
// #####

// Constructor
// #####
GameEngine::GameEngine() {
    // Create window : getDesktopMode() = current window_width/window_heigth; name of the window and window mode.
    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "EtnaZ-Engine", sf::Style::Default, sf::State::Windowed);
    dt = 0;
}
// #####


// Destructor
// ######
GameEngine::~GameEngine() {
    delete window;
    window = nullptr;

    for (auto& aS : activeStates) {
        delete aS;
        aS = nullptr;
    }

    for (auto& s : states) {
        delete s;
        s = nullptr;
    }
}
// ######

// Update the event
// ######
void GameEngine::updateEvent() {
    Input::getInstance()->reset();
    while (const std::optional event = window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window->close();
        }
        Input::getInstance()->setEvent(*event);
    }
}
// ######

// Update the delta time
// ######
void GameEngine::updateTime() {
    sf::Time elapsed = clock.getElapsedTime();
    clock.restart();
    dt = elapsed.asSeconds();
}
// ######

// update the current scene
// ######
void GameEngine::update() {
    if (!activeStates.empty()) {
        activeStates.back()->manageState();
        activeStates.back()->update(dt);
    }
}
// ######

// Render the current scene
// ######
void GameEngine::render() {
    if (!states.empty()) {
        states.back()->render();
    }
    if (!activeStates.empty()) {
        activeStates.back()->render();
    }
}
// ######

// Main loop
// ######
void GameEngine::run() {

    Textures::getTexturesManager()->loadAllTexture();
    activeStates.push_back(Menu::getInstance(MenuType::MainMenu));

    while (window->isOpen()) {
        updateEvent();
        updateTime();
        update();
        window->clear();
        render();
        window->display();
    }
}
// ######