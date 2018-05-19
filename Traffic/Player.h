#pragma once
#include <SFML/Graphics.hpp>

class Player : public sf::Sprite {
public:
	Player();
	int getRealWidth();
	int getRealHeight();
};