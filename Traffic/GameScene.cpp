#include "GameScene.h"
#include "Files.h"
#include "Road.h"
#include "RoadManager.h"
#include "Properties.h"
#include "Player.h"
#include "Coin.h"
#include "InputHandler.h"

std::list<GameObject2D*> gameObjects2D;
std::list<GameObject*> gameObjects;

GameScene::GameScene(sf::RenderWindow * window)
{
	this->window = window;
	setupRoads();
	setupPlayer();
	setupInput();
	setupCoinManager();
}

void GameScene::process(float delta)
{

	for (auto const& i : gameObjects) {
		i->process(2.0);
	}

	for (auto const& i : gameObjects2D) {
		i->process(2.0);
		window->draw(*i);
	}

	handleCollisions();
}

void GameScene::handleCollisions() {
	std::list<Coin*> collidedCoins = coinManager->checkCollision(player);

	for (auto const& coin : collidedCoins) {
		gameObjects2D.remove(coin);
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
	std::list<Coin*> coins = coinManager->generateCoins();
	for (auto const& coin : coins) gameObjects2D.push_back(coin);
}

void GameScene::setupCarManager()
{
}

void GameScene::setupInput() {
	input = new InputHandler(player);
	gameObjects.push_back(input);
}