#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SFML/Graphics.hpp>

class GameObject : public sf::Sprite {
public:
	virtual void process(float delta) = 0;
	void loadTexture(std::string path);
private:
	sf::Texture texture;
};

#endif