#include "Road.h"


Road::Road() {};

void Road::process(float delta)
{
	move(sf::Vector2f(0, speed));
}

void Road::setSpeed(int speed) {
	this->speed = speed;
}
