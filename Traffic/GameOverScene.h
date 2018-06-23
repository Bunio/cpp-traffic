#ifndef GAME_OVER_SCENE_H
#define GAME_OVER_SCENE_H

#include "GameObject.h"
#include "GameObject2D.h"
#include "Button.h"
#include "Files.h"
#include "Properties.h"
#include <SFML/Graphics.hpp>
#include <list>

class GameOverScene : public GameObject {
public:
	GameOverScene(sf::RenderWindow* window);
	void process(float delta);
private:
	sf::RenderWindow* window;
	Button* restartBtn;
	void setupButtons();
};

#endif