#include "Road.h"
#include "Properties.h"


Road::Road() {};

void Road::process(float delta)
{
	move(sf::Vector2f(0, speed * Properties::SPEED_MODIFIER *  delta));
}

void Road::setSpeed(int speed) {
	this->speed = speed;
}
