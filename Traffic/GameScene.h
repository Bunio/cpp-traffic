#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "GameObject.h"
#include "GameObject2D.h"
#include "RoadManager.h"
#include "Player.h"
#include "InputHandler.h"
#include <SFML/Graphics.hpp>

class GameScene : public GameObject {
public:
	GameScene(sf::RenderWindow* window);
	void process(float delta);
private:
	sf::RenderWindow* window;
	void setupPlayer();
	void setupInput();
	void setupRoads();

	Player* player;
	RoadManager* roadManager;
	InputHandler* input;
};

#endif