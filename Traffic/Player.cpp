#include <SFML/Graphics.hpp>
#include "Player.h"

float speed_cur = 1.0;
const float speed_max = 15;
const float speed_vel = 1.05;
const float speed_friction = 0.95;

void Player::process(float delta) {
	if (speed_cur > speed_max) {
		speed_cur = speed_max;
	}

	sf::Sprite::move(speed_cur, 0);
	speed_cur *= speed_friction;
}


void Player::moveLeft() {
		speed_cur -= 1 * speed_vel;

	}

void Player::moveRight() {
		speed_cur += 1 * speed_vel;
	}

	// Utility methods ------------------

int Player::getRealWidth() {
		return sf::Sprite::getLocalBounds().width * sf::Sprite::getScale().x;
	}
int Player::getRealHeight() {
		return sf::Sprite::getLocalBounds().height * sf::Sprite::getScale().y;
	}