#include <SFML/Graphics.hpp>
#include "InputHandler.h"




InputHandler::InputHandler(Player* player) { this->player = player; }

void InputHandler::process(float delta) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			player->moveLeft();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			player->moveRight();
		}
	}
