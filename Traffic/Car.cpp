#include <iostream>
#include "Car.h"
#include "Properties.h" 

Car::Car(int speed)
{
	setSpeed(speed);
}

void Car::process(float delta)
{
	move(sf::Vector2f(0, speed * Properties::SPEED_MODIFIER * delta));
}

void Car::setSpeed(int speed)
{
	this->speed = speed;
}
