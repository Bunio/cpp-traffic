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
