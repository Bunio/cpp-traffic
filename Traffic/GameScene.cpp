#include "GameScene.h"
#include "Files.h"
#include "Road.h"
#include "RoadManager.h"
#include "Properties.h"
#include "Player.h"
#include "Coin.h"
#include "InputHandler.h"

std::vector<GameObject2D*> gameObjects2D;
std::vector<GameObject*> gameObjects;

GameScene::GameScene(sf::RenderWindow * window)
{
	this->window = window;
	setupRoads();
	setupPlayer();
	setupInput();
	setupCoinManager();
	/*
	Coin coin(10);
	coin.loadTexture(Files::TEXTURE_COIN);
	coin.setPosition(50, 0);

	gameObjects2D.push_back(&coin);*/

}

void GameScene::process(float delta)
{
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->process(2.0);
	}
	for (int i = 0; i < gameObjects2D.size(); i++) {
		gameObjects2D[i]->process(2.0);
		window->draw(*gameObjects2D[i]);
	}
}

void GameScene::setupPlayer() {
	player = new Player();
	player->loadTexture(Files::TEXTURE_MOTORBIKE);
	player->scale(0.35, 0.35);
	player->setPosition(Properties::SCENE_WIDTH / 2 - player->getRealWidth() / 2, Properties::SCENE_HEIGHT - player->getRealHeight() - 20);
	gameObjects2D.push_back(player);
}

void GameScene::setupRoads() {
	roadManager = new RoadManager();
	gameObjects.push_back(roadManager);
	gameObjects2D.push_back(roadManager->getRoads()[0]);
	gameObjects2D.push_back(roadManager->getRoads()[1]);
}

void GameScene::setupCoinManager()
{
	coinManager = new CoinManager();
	gameObjects.push_back(coinManager);

	std::vector<Coin*> coins = coinManager->generateCoins();
	
	for (int i = 0; i < coins.size(); i++) {
		gameObjects2D.push_back(coins[i]);
	}

}

void GameScene::setupCarManager()
{
}

void GameScene::setupInput() {
	input = new InputHandler(player);
	gameObjects.push_back(input);
}