#pragma once
#include "GameState.h"

class Game;

class MainMenu : public GameState
{
private:

public:
	MainMenu() = default;
	MainMenu(RenderWindow* window, vector<GameState*>* states, Input& input);
	~MainMenu() = default;

	static void Instance(RenderWindow* window, vector<GameState*>*& states, Input& input);

	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};

