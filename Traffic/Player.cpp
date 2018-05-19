#include "Player.h"

Player::Player() : sf::Sprite() {};

float speed_cur = 1.0;
const float speed_max = 15;
const float speed_vel = 1.05;
const float speed_friction = 0.95;

void Player::process(float delta) {

	// TODO: Handle delta 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		speed_cur -= 1 * speed_vel;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		speed_cur += 1 * speed_vel;
	}

	if (speed_cur > speed_max) {
		speed_cur = speed_max;
	}

	sf::Sprite::move(speed_cur, 0);
	speed_cur *= speed_friction;
}

// Utility methods ------------------

int Player::getRealWidth() { 
	return sf::Sprite::getLocalBounds().width * sf::Sprite::getScale().x;
}
int Player::getRealHeight() {
	return sf::Sprite::getLocalBounds().height * sf::Sprite::getScale().y;
}




