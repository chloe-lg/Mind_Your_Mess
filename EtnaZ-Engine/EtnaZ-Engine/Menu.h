#pragma once
#include <iostream>
#include "GameObject.h"
#include "GameState.h"
#include "Globals.h"


class GameEngine;

class Game;

enum MenuType {
	MainMenu,
	PauseMenu,
	GameOverMenu,
	WinMenu
};

class Menu : public GameState {

private:
    Menu();
    Menu(MenuType type);

	MenuType menuType;

    static Menu* instance[4];
    GameObject* Title = nullptr;
    GameObject* btnStart = nullptr;   
    GameObject* btnQuit = nullptr;
	GameObject* btnResume = nullptr;
	GameObject* btnRestart = nullptr;
	GameObject* imgGameOver = nullptr;
	GameObject* imgWin = nullptr;
	GameObject* imgPause = nullptr;
    sf::RectangleShape bgMenu;
    sf::RectangleShape pauseLayer;

    float cx = WIN_WIDTH / 2.f;
    float cy = WIN_HEIGHT / 2.f;
    
public:
    virtual ~Menu() override;

    static GameState* getInstance(MenuType type);

	bool isClicked(GameObject* button);

    virtual void manageState() override;
    virtual void update(float& dt) override;
    virtual void render() override;
};
