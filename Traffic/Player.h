#pragma once
#include <SFML/Graphics.hpp>

class Player : public sf::Sprite {
public:
	Player();
	void process(float delta);
	void moveLeft();
	void moveRight();
	int getRealWidth();
	int getRealHeight();
};