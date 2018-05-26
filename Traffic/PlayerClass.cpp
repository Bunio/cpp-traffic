#include <SFML/Graphics.hpp>
#include "GameObject.cpp"

class PlayerClass : public GameObject, public sf::Sprite {
public:
	float speed_cur = 1.0;
	const float speed_max = 15;
	const float speed_vel = 1.05;
	const float speed_friction = 0.95;

	void process(float delta) {
		if (speed_cur > speed_max) {
			speed_cur = speed_max;
		}

		//sf::Sprite::move(speed_cur, 0);
		speed_cur *= speed_friction;
	}


	// Handled by InputHandler ---------

	void moveLeft() {
		speed_cur -= 1 * speed_vel;

	}

	void moveRight() {
		speed_cur += 1 * speed_vel;
	}

	// Utility methods ------------------

	int getRealWidth() {
		return sf::Sprite::getLocalBounds().width * sf::Sprite::getScale().x;
	}
	int getRealHeight() {
		return sf::Sprite::getLocalBounds().height * sf::Sprite::getScale().y;
	}
};