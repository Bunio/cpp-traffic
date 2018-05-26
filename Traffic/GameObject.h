#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SFML/Graphics.hpp>

class GameObject {
public:
	virtual void process(float delta) = 0;
};

#endif