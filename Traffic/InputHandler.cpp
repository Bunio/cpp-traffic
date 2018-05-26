#include "PlayerClass.cpp"
#include <SFML/Graphics.hpp>

class InputHandler {
public:
	InputHandler(PlayerClass* player) {
		this->player = player;
	}
	void handleInput(float delta) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			player->moveLeft();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			player->moveRight();
		}
	}

private:
	PlayerClass* player;

};
