#include <iostream>
#include "Car.h"

Car::Car(int speed)
{
	setSpeed(speed);
}

void Car::process(float delta)
{
	move(sf::Vector2f(0, speed * delta));
}

void Car::setSpeed(int speed)
{
	this->speed = speed;
}
