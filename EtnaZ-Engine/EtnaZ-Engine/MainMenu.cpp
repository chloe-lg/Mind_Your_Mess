#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu(RenderWindow* window, vector<GameState*>* _states, Input& _input) : GameState(window, _states, _input) {

}

void MainMenu::Instance(RenderWindow* window, vector<GameState*>*& states, Input& input) {
	GameState* mainMenu = new MainMenu(window, states, input);
	states->push_back(mainMenu);
}

void MainMenu::manageState() {
	if (input.isKeyPressed(Keyboard::Key::Enter)) {
		GameState::nextState(states);
		Game::Instance(window, states, input);
	}
}

void MainMenu::update(float& dt) {

}

void MainMenu::render() {
	cout << "Menu" << endl;
}

