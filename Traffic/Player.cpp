#include "Player.h"

Player::Player() : sf::Sprite() {};

int Player::getRealWidth() { 
	return sf::Sprite::getLocalBounds().width * sf::Sprite::getScale().x;
}
int Player::getRealHeight() {
	return sf::Sprite::getLocalBounds().height * sf::Sprite::getScale().y;
}