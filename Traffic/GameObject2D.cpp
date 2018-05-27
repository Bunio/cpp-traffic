#include "GameObject2D.h"
#include <iostream>

void GameObject2D::loadTexture(std::string path)
{
	if (!texture.loadFromFile(path))
	{
		std::cout << "Error loading image";
	}
	
	this->setTexture(texture);
	
}

int GameObject2D::getRealWidth() {
	return sf::Sprite::getLocalBounds().width * sf::Sprite::getScale().x;
}
int GameObject2D::getRealHeight() {
	return sf::Sprite::getLocalBounds().height * sf::Sprite::getScale().y;
}
