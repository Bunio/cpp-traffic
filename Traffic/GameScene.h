#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "GameObject.h"
#include "GameObject2D.h"
#include "RoadManager.h"
#include "Player.h"
#include "InputHandler.h"
#include "CoinManager.h"
#include "CarManager.h"
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
	void setupCoinManager();
	void setupCarManager();
	void handleCollisions();

	Player* player;
	RoadManager* roadManager;
	InputHandler* input;
	CoinManager* coinManager;
	CarManager* carManager;
};

#endif