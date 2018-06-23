#include "GameOverScene.h"
#include "SceneManager.h"


std::list<Button*>* gameOverButtons;
sf::Texture* _texture;
sf::Sprite* _background;

GameOverScene::GameOverScene(sf::RenderWindow * window)
{
	// Setup background
	_background = new sf::Sprite();
	_texture = new sf::Texture();
	_texture->loadFromFile(Files::TEXTURE_BACKGROUND);
	_background->setTexture(*_texture);

	this->window = window;
	gameOverButtons = new std::list<Button*>();
	setupButtons();
}

void GameOverScene::process(float delta)
{
	window->draw(*_background);

	for (auto const& i : *gameOverButtons) {
		i->process(delta);
		window->draw(*i);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			std::cout << "CLICK";

			sf::Vector2i p = sf::Mouse::getPosition(*window);
			sf::Vector2<float> pos(p.x, p.y);


			bool mouseInButton = i->getGlobalBounds().contains(pos);
			if (mouseInButton) {
				std::cout << "CLICK ON BUTTON";
				SceneManager::setScene(2, window);
			}
		}
	}
}

void GameOverScene::setupButtons()
{
	restartBtn = new Button();
	restartBtn->loadTexture(Files::TEXTURE_RESTART_BUTTON);
	//restartBtn->scale(0.25, 0.25);
	restartBtn->setPosition(Properties::SCENE_WIDTH / 2 - restartBtn->getRealWidth() / 2, Properties::SCENE_HEIGHT - restartBtn->getRealHeight() - 650);
	gameOverButtons->push_back(restartBtn);
}
