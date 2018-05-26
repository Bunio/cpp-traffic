#ifndef GAME_OBJECT_2D_H
#define GAME_OBJECT_2D_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class GameObject2D : public GameObject, public sf::Sprite {
public:
	void loadTexture(std::string path);
private:
	sf::Texture texture;
};

#endif