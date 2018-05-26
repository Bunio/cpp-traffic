#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "GameObject2D.h"

class Player : public GameObject2D{
public:
	void process(float delta);
	void moveLeft();
	void moveRight();
	int getRealWidth();
	int getRealHeight();
};

#endif