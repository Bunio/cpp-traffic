#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Player : public GameObject, public sf::Sprite {
public:
	void process(float delta);
	void moveLeft();
	void moveRight();
	int getRealWidth();
	int getRealHeight();
};

#endif