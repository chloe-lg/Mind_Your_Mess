#include "Menu.h"
#include "Textures.h"


#include <SFML/Window/Keyboard.hpp>

#include "GameEngine.h"
#include "Game.h"

Menu* Menu::instance[4] = { nullptr, nullptr, nullptr, nullptr };

Menu::Menu() {

}

Menu::~Menu() {
    delete Title;
    delete btnStart;
    delete btnQuit;
    delete btnResume;
    delete btnRestart;
    delete imgGameOver;
    delete imgWin;
    delete imgPause;
}

Menu::Menu(MenuType type) : menuType(type) {
    sf::Texture& bgTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::bg_menu);
    float bgTextureWidth = (float)bgTexture.getSize().x;
    float bgTextureHeight = (float)bgTexture.getSize().y;

    if (bgTextureWidth > 0.f && bgTextureHeight > 0.f) {
        float bgScaleX = WIN_WIDTH / bgTextureWidth;
        float bgScaleY = WIN_HEIGHT / bgTextureHeight;
        float bgScale = bgScaleX;

        if (bgScaleY > bgScale) {
            bgScale = bgScaleY;
        }

        float bgFinalWidth = bgTextureWidth * bgScale;
        float bgFinalHeight = bgTextureHeight * bgScale;

        bgMenu.setTexture(&bgTexture);
        bgMenu.setSize({ bgTextureWidth, bgTextureHeight });
        bgMenu.setScale({ bgScale, bgScale });
        bgMenu.setPosition({ (WIN_WIDTH - bgFinalWidth) / 2.f, (WIN_HEIGHT - bgFinalHeight) / 2.f });
    }

    pauseLayer.setPosition({ 0.f, 0.f });
    pauseLayer.setSize({ WIN_WIDTH, WIN_HEIGHT });
    pauseLayer.setFillColor(sf::Color(60, 60, 60, 140));

    float bigImageWidth = 620.f;
    float buttonWidth = 320.f;
    float imageTopY = cy - 420.f;
    float gapAfterImage = 90.f;
    float gapBetweenButtons = 50.f;

    switch (menuType) {

    case MenuType::MainMenu:
    {
        sf::Texture& titleTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::title);
        float titleWidth = (float)titleTexture.getSize().x;
        float titleHeight = (float)titleTexture.getSize().y;
        float finalTitleHeight = bigImageWidth * 0.5f;

        if (titleWidth > 0.f && titleHeight > 0.f) {
            finalTitleHeight = bigImageWidth * (titleHeight / titleWidth);
        }

        Title = new GameObject(cx - bigImageWidth / 2.f, imageTopY, bigImageWidth, finalTitleHeight);
        Title->setTexture(&titleTexture);

        sf::Texture& startTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::btn_start);
        float startWidth = (float)startTexture.getSize().x;
        float startHeight = (float)startTexture.getSize().y;
        float finalStartHeight = buttonWidth * 0.5f;

        if (startWidth > 0.f && startHeight > 0.f) {
            finalStartHeight = buttonWidth * (startHeight / startWidth);
        }

        float startY = Title->getPos().y + Title->getSize().y + gapAfterImage;
        btnStart = new GameObject(cx - buttonWidth / 2.f, startY, buttonWidth, finalStartHeight);
        btnStart->setTexture(&startTexture);

        sf::Texture& quitTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::btn_quit);
        float quitWidth = (float)quitTexture.getSize().x;
        float quitHeight = (float)quitTexture.getSize().y;
        float finalQuitHeight = buttonWidth * 0.5f;

        if (quitWidth > 0.f && quitHeight > 0.f) {
            finalQuitHeight = buttonWidth * (quitHeight / quitWidth);
        }

        float quitY = btnStart->getPos().y + btnStart->getSize().y + gapBetweenButtons;
        btnQuit = new GameObject(cx - buttonWidth / 2.f, quitY, buttonWidth, finalQuitHeight);
        btnQuit->setTexture(&quitTexture);
        break;
    }

    case MenuType::PauseMenu:
    {
        sf::Texture& pauseTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::title);
        float pauseWidth = (float)pauseTexture.getSize().x;
        float pauseHeight = (float)pauseTexture.getSize().y;
        float finalPauseHeight = bigImageWidth * 0.5f;

        if (pauseWidth > 0.f && pauseHeight > 0.f) {
            finalPauseHeight = bigImageWidth * (pauseHeight / pauseWidth);
        }

        imgPause = new GameObject(cx - bigImageWidth / 2.f, imageTopY, bigImageWidth, finalPauseHeight);
        imgPause->setTexture(&pauseTexture);

        sf::Texture& resumeTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::btn_resume);
        float resumeWidth = (float)resumeTexture.getSize().x;
        float resumeHeight = (float)resumeTexture.getSize().y;
        float finalResumeHeight = buttonWidth * 0.5f;

        if (resumeWidth > 0.f && resumeHeight > 0.f) {
            finalResumeHeight = buttonWidth * (resumeHeight / resumeWidth);
        }

        float resumeY = imgPause->getPos().y + imgPause->getSize().y + gapAfterImage;
		btnResume = new GameObject(cx - buttonWidth / 2.f, resumeY, buttonWidth, finalResumeHeight);
		btnResume->setTexture(&resumeTexture);

        sf::Texture& quitTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::btn_quit);
        float quitWidth = (float)quitTexture.getSize().x;
        float quitHeight = (float)quitTexture.getSize().y;
        float finalQuitHeight = buttonWidth * 0.5f;

        if (quitWidth > 0.f && quitHeight > 0.f) {
            finalQuitHeight = buttonWidth * (quitHeight / quitWidth);
        }

        float quitY = btnResume->getPos().y + btnResume->getSize().y + gapBetweenButtons;
		btnQuit = new GameObject(cx - buttonWidth / 2.f, quitY, buttonWidth, finalQuitHeight);
		btnQuit->setTexture(&quitTexture);
        break;
    }

    case MenuType::GameOverMenu:
    {
        sf::Texture& gameOverTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::img_gameover);
        float gameOverWidth = (float)gameOverTexture.getSize().x;
        float gameOverHeight = (float)gameOverTexture.getSize().y;
        float finalGameOverHeight = bigImageWidth * 0.5f;

        if (gameOverWidth > 0.f && gameOverHeight > 0.f) {
            finalGameOverHeight = bigImageWidth * (gameOverHeight / gameOverWidth);
        }

        imgGameOver = new GameObject(cx - bigImageWidth / 2.f, imageTopY, bigImageWidth, finalGameOverHeight);
        imgGameOver->setTexture(&gameOverTexture);

        sf::Texture& restartTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::btn_restart);
        float restartWidth = (float)restartTexture.getSize().x;
        float restartHeight = (float)restartTexture.getSize().y;
        float finalRestartHeight = buttonWidth * 0.5f;

        if (restartWidth > 0.f && restartHeight > 0.f) {
            finalRestartHeight = buttonWidth * (restartHeight / restartWidth);
        }

        float restartY = imgGameOver->getPos().y + imgGameOver->getSize().y + gapAfterImage;
        btnRestart = new GameObject(cx - buttonWidth / 2.f, restartY, buttonWidth, finalRestartHeight);
        btnRestart->setTexture(&restartTexture);

        sf::Texture& quitTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::btn_quit);
        float quitWidth = (float)quitTexture.getSize().x;
        float quitHeight = (float)quitTexture.getSize().y;
        float finalQuitHeight = buttonWidth * 0.5f;

        if (quitWidth > 0.f && quitHeight > 0.f) {
            finalQuitHeight = buttonWidth * (quitHeight / quitWidth);
        }

        float quitY = btnRestart->getPos().y + btnRestart->getSize().y + gapBetweenButtons;
        btnQuit = new GameObject(cx - buttonWidth / 2.f, quitY, buttonWidth, finalQuitHeight);
        btnQuit->setTexture(&quitTexture);
        break;
    }

    case MenuType::WinMenu:
    {
        sf::Texture& winTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::img_win);
        float winWidth = (float)winTexture.getSize().x;
        float winHeight = (float)winTexture.getSize().y;
        float finalWinHeight = bigImageWidth * 0.5f;

        if (winWidth > 0.f && winHeight > 0.f) {
            finalWinHeight = bigImageWidth * (winHeight / winWidth);
        }

        imgWin = new GameObject(cx - bigImageWidth / 2.f, imageTopY, bigImageWidth, finalWinHeight);
        imgWin->setTexture(&winTexture);

        sf::Texture& restartTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::btn_restart);
        float restartWidth = (float)restartTexture.getSize().x;
        float restartHeight = (float)restartTexture.getSize().y;
        float finalRestartHeight = buttonWidth * 0.5f;

        if (restartWidth > 0.f && restartHeight > 0.f) {
            finalRestartHeight = buttonWidth * (restartHeight / restartWidth);
        }

        float restartY = imgWin->getPos().y + imgWin->getSize().y + gapAfterImage;
        btnRestart = new GameObject(cx - buttonWidth / 2.f, restartY, buttonWidth, finalRestartHeight);
        btnRestart->setTexture(&restartTexture);

        sf::Texture& quitTexture = Textures::getTexturesManager()->getTexture(Textures::texturesIndices::btn_quit);
        float quitWidth = (float)quitTexture.getSize().x;
        float quitHeight = (float)quitTexture.getSize().y;
        float finalQuitHeight = buttonWidth * 0.5f;

        if (quitWidth > 0.f && quitHeight > 0.f) {
            finalQuitHeight = buttonWidth * (quitHeight / quitWidth);
        }

        float quitY = btnRestart->getPos().y + btnRestart->getSize().y + gapBetweenButtons;
        btnQuit = new GameObject(cx - buttonWidth / 2.f, quitY, buttonWidth, finalQuitHeight);
        btnQuit->setTexture(&quitTexture);
        break;
    }
    }
}

GameState* Menu::getInstance(MenuType type) {
   if (instance[type] == nullptr) {
        instance[type] = new Menu(type);
    }
   return instance[type];
}


bool Menu::isClicked(GameObject* button) {
	Input* input = Input::getInstance();
    if (input->isMousePressed(sf::Mouse::Button::Left)) {
        sf::Vector2i mousePos = input->getMousePos();
        sf::FloatRect rect(button->getPos(), button->getSize());
        if (rect.contains((sf::Vector2f)mousePos)) {
            return true;
        }
    }
    return false;
}

void Menu::manageState() {
    if (menuType == MenuType::MainMenu) {
        if (isClicked(btnStart)) {
            nextState();
            GameEngine::activeStates.push_back(Game::getInstance());
        }
        else if (isClicked(btnQuit)) {
            GameEngine::window->close();
        }
    }
    else if (menuType == MenuType::PauseMenu) {
        if (isClicked(btnResume)) { 
            resume();
        }
        else if (isClicked(btnQuit)) {
            GameEngine::window->close();
        }
    }
    else if (menuType == MenuType::GameOverMenu || menuType == MenuType::WinMenu) {
        if (isClicked(btnRestart)) {
			Game::resetInstance();
			nextState();
            GameEngine::activeStates.push_back(Game::getInstance());
        }
        else if (isClicked(btnQuit)) {
            GameEngine::window->close();
        }
	}
    
}

void Menu::update(float& dt) {

}

void Menu::render() {

    if (menuType == MenuType::PauseMenu) {
        GameEngine::window->setView(GameEngine::window->getDefaultView());
        GameEngine::window->draw(pauseLayer);
        imgPause->render();
        btnResume->render();
		btnQuit->render();
    }
    else if (menuType == MenuType::GameOverMenu) {
        GameEngine::window->setView(GameEngine::window->getDefaultView());
        GameEngine::window->draw(bgMenu);
        imgGameOver->render();
        btnRestart->render();
		btnQuit->render();
    }
    else if (menuType == MenuType::WinMenu) {
        GameEngine::window->setView(GameEngine::window->getDefaultView());
        GameEngine::window->draw(bgMenu);
        imgWin->render();
        btnRestart->render();
		btnQuit->render();
	}
    else if (menuType == MenuType::MainMenu) {
        GameEngine::window->setView(GameEngine::window->getDefaultView());
        GameEngine::window->draw(bgMenu);
        Title->render();
        btnStart->render();
        btnQuit->render();
    }

}
