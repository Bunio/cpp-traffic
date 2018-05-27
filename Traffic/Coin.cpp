#include <iostream>
#include "Coin.h"

Coin::Coin(int speed)
{
	setSpeed(speed);
}

void Coin::process(float delta)
{
	move(sf::Vector2f(0, speed * delta));
}

void Coin::collect()
{
	std::cout << "Collect !";
}

void Coin::setSpeed(int speed)
{
	this->speed = speed;
}
