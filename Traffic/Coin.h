#ifndef COIN_H
#define COIN_H

#include "GameObject2D.h"

class Coin : public GameObject2D {
public:
	Coin(int speed);
	void process(float delta);
	void collect();
	void setSpeed(int speed);
private:
	int speed;
	int value;

};

#endif