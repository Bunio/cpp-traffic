#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "GameObject.h"

class Player : public GameObject{
public:
	void process(float delta);
	void moveLeft();
	void moveRight();
	int getRealWidth();
	int getRealHeight();
};

#endif