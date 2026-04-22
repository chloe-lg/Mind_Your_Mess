#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "Globals.h"
#include "Camera.h"
#include "SFML/Graphics.hpp"
#include <iostream>
 
class LoadLevel;

class GameEngine;

class Game : public GameState {

private:
    // Variable for scene
    Game();

    static Game* instance;
private:
    // Object in my scene
    // Vec for update
    std::vector<GameObject*> entityCreate;
    std::vector<GameObject*> entityNoCollidable;
    std::vector<GameObject*> entityCollidable;

    // Vec for render
    std::vector<std::vector<GameObject*>> vecRender;
    sf::RectangleShape bgGame;

    Player* myPlayer = nullptr;
	LoadLevel* myLevel = nullptr;
    Camera* myCamera = nullptr;


public:
    virtual ~Game() override;

    static GameState* getInstance();

    static void resetInstance();

    void setEntity();

    void gameOver();
    void win();

    virtual void manageState() override;
    virtual void update(float& dt) override;
    virtual void render() override;

    // Colision
    void collisions();
    void setCollision();

    // Layer
    void addObjetcInLayer(GameObject* myObject, int Layer);
    void setLayer(int nbrLayer);

};
