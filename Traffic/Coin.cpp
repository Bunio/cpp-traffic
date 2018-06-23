#include <iostream>
#include "Coin.h"
#include "Properties.h"

Coin::Coin(int speed)
{
	setSpeed(speed);
}

void Coin::process(float delta)
{
	move(sf::Vector2f(0, speed * Properties::SPEED_MODIFIER * delta));
}

void Coin::collect()
{
	std::cout << "Collect !";
}

void Coin::setSpeed(int speed)
{
	this->speed = speed;
}
