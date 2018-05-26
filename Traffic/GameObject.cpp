#include "GameObject.h"
#include <iostream>

void GameObject::loadTexture(std::string path)
{
	if (!texture.loadFromFile(path))
	{
		std::cout << "Error loading image";
	}
	
	this->setTexture(texture);
	
}
