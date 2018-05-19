#include "InputHandler.h"
#include "Player.h"


InputHandler::InputHandler(Player* player) {}

void InputHandler::handleInput(float delta) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player->moveLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player->moveRight();
	}
}