#include "Game.h"
#include "Textures.h"
#include "Player.h"
#include "LoadLevel.h"

#include <SFML/Window/Keyboard.hpp>

#include "GameEngine.h"

Game* Game::instance = nullptr;

Game::Game() {
   
}

Game::~Game() {
    delete myCamera;
    myCamera = nullptr;

    delete myLevel;
    myLevel = nullptr;

    delete myPlayer;
    myPlayer = nullptr;

    entityCreate.clear();
    entityNoCollidable.clear();
    entityCollidable.clear();
    instance = nullptr;
}

GameState* Game::getInstance() {
    if (instance == nullptr) {
        instance = new Game();
		instance->setEntity();
    }
    return instance;
}

void Game::resetInstance(){
    delete instance;  
    instance = nullptr;
}

void Game::setEntity() {
    setLayer(3);

    myPlayer = new Player(50, 50, 80, 80);
    myPlayer->setTexture(&Textures::getTexturesManager()->getTexture(Textures::texturesIndices::sushi_s));

    Collider* myCollider = new Collider(myPlayer);
    myPlayer->setCollider(myCollider);

    entityCreate.push_back(myPlayer);
    addObjetcInLayer(myPlayer, 2);

    myLevel = new LoadLevel();
    myLevel->loadLevel();
    myLevel->assignTextures();

    myPlayer->setPos({ myLevel->spawnX, myLevel->spawnY });

    sf::Texture& bgTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::bg_game);
    bgTexture.setRepeated(true);

    float textureWidth = (float)bgTexture.getSize().x;
    float textureHeight = (float)bgTexture.getSize().y;

    if (textureWidth > 0.f && textureHeight > 0.f) {
        float scale = PLAYABLE_WIDTH / textureWidth;
        float localHeight = LEVEL_HEIGHT / scale;

        bgGame.setPosition({ 0.f, 0.f });
        bgGame.setTexture(&bgTexture);
        bgGame.setSize({ textureWidth, localHeight });
        bgGame.setScale({ scale, scale });
        bgGame.setTextureRect(sf::IntRect({ 0, 0 }, { (int)textureWidth, (int)localHeight }));
    }

    for (auto& k : myLevel->knife) {
        entityCreate.push_back(k);
        addObjetcInLayer(k, 1);
    }

    for (auto& p : myLevel->plate) {
        entityCreate.push_back(p);
        addObjetcInLayer(p, 1);
    }

    for (auto& s : myLevel->soy) {
        entityCreate.push_back(s);
        addObjetcInLayer(s, 1);
    }

    for (auto& f : myLevel->finish) {
        entityCreate.push_back(f);
    }

    setCollision();

    myCamera = new Camera(165.f);
    myCamera->target = myPlayer;
}

void Game::manageState() {
    if (Input::getInstance()->isKeyPressed(sf::Keyboard::Key::Escape)) {
        pause();
        GameEngine::activeStates.push_back(Menu::getInstance(MenuType::PauseMenu));
    }
}

void Game::update(float& dt) {
    myCamera->update(dt);
    if (myCamera->isCaught(myPlayer)) {
        nextState();
        GameEngine::activeStates.push_back(Menu::getInstance(MenuType::GameOverMenu));     
		return;

    }

    for (auto& e : entityNoCollidable) {
        e->update(dt);
    }
    for (auto& e : entityCollidable) {
        e->update(dt);
    }

    collisions();
}

void Game::render() {
    GameEngine::window->setView(myCamera->getView());
    GameEngine::window->draw(bgGame);

    for (auto& vR : vecRender) {
        for (auto& e : vR) {
            e->render();
        }
    }

    GameEngine::window->setView(GameEngine::window->getDefaultView());

}

void Game::collisions() {
    if (myPlayer->getCollider() != nullptr) {
        for (auto& eC : entityCollidable) {
            if (eC != myPlayer && myPlayer->getCollider()->isColliding(eC)){
                eC->onPlayerCollide(this, myPlayer);
            }
        }
    }
}

void Game::gameOver() {
    nextState();
    GameEngine::activeStates.push_back(Menu::getInstance(MenuType::GameOverMenu));
}

void Game::win() {
    nextState();
    GameEngine::activeStates.push_back(Menu::getInstance(MenuType::WinMenu));
}

void Game::setCollision() {
    if (!entityCreate.empty()) {
        for (auto& e : entityCreate) {
            if (e->getCollider() != nullptr && e->getCollider()->isCollidable()) {
                entityCollidable.push_back(e);
            }
            else {
                entityNoCollidable.push_back(e);
            }
        }
    }
}

void Game::addObjetcInLayer(GameObject* myObject, int Layer) {
    if (!vecRender.empty() && Layer < vecRender.size()) {
        vecRender[Layer].push_back(myObject);
    }
}

void Game::setLayer(int _nbrLayer) {
    for (int X = 0; X < _nbrLayer; X++) {
        std::vector<GameObject*>  layer;
        vecRender.push_back(layer);
    }
}
