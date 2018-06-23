#include "MenuScene.h"
#include "SceneManager.h"

std::list<Button*> buttons;

MenuScene::MenuScene(sf::RenderWindow * window)
{
	this->window = window;
	setupButtons();
}

void MenuScene::process(float delta)
{
	for (auto const& i : buttons) {
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

void MenuScene::setupButtons()
{
	newGameBtn = new Button();
	newGameBtn->loadTexture(Files::TEXTURE_NEW_GAME_BUTTON);
	newGameBtn->scale(0.25, 0.25);
	newGameBtn->setPosition(Properties::SCENE_WIDTH / 2 - newGameBtn->getRealWidth() / 2, Properties::SCENE_HEIGHT - newGameBtn->getRealHeight() - 20);
	buttons.push_back(newGameBtn);
}
