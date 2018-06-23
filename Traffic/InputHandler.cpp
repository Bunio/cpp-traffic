#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "Properties.h"




InputHandler::InputHandler(Player* player) { this->player = player; }

void InputHandler::process(float delta) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			player->moveLeft();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			player->moveRight();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			Properties::SPEED_MODIFIER = 1.85;
		} 
		else {
			Properties::SPEED_MODIFIER = 1.0;
		}

	}
