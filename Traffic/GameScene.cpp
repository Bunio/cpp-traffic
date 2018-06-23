#include "GameScene.h"
#include "Files.h"
#include "Road.h"
#include "RoadManager.h"
#include "Properties.h"
#include "Player.h"
#include "Coin.h"
#include "InputHandler.h"
#include "SceneManager.h"

std::list<GameObject2D*>* gameObjects2D;
std::list<GameObject*>* gameObjects;
//std::list<GameObject*>* gameObjects2;

GameScene::GameScene(sf::RenderWindow * window)
{

	// TODO: REFACTOR / MOVE TO METHODS
	gameObjects2D = new std::list<GameObject2D*>();
	gameObjects = new std::list<GameObject*>();
	this->window = window;
	Properties::SPEED_MODIFIER = Properties::SPEED_MODIFIER_MIN;
	// -----------------------------------

	setupRoads();
	setupPlayer();
	setupInput();
	setupCoinManager();
	setupCarManager();
}

void GameScene::process(float delta)
{
	for (auto const& i : *gameObjects) {
		i->process(delta);
	}

	for (auto const& i : *gameObjects2D) {
		i->process(delta);
		window->draw(*i);
	}

	handleCollisions();
}

void GameScene::handleCollisions() {
	coinManager->checkCollision(player);

	if (carManager->checkCollision(player).size() > 0) {
		SceneManager::setScene(3);
	}
	else if (player->getPosition().x > Properties::SCENE_WIDTH || player->getPosition().x < -player->getRealWidth()) {
		SceneManager::setScene(3);
	}
}

void GameScene::setupPlayer() {
	player = new Player();
	player->loadTexture(Files::TEXTURE_MOTORBIKE);
	player->scale(0.25, 0.25);
	player->setPosition(Properties::SCENE_WIDTH / 2 - player->getRealWidth() / 2, Properties::SCENE_HEIGHT - player->getRealHeight() - 20);
	gameObjects2D->push_back(player);
}

void GameScene::setupRoads() {
	roadManager = new RoadManager();
	gameObjects->push_back(roadManager);
	gameObjects2D->push_back(roadManager->getRoads()[0]);
	gameObjects2D->push_back(roadManager->getRoads()[1]);
}

void GameScene::setupCoinManager()
{
	coinManager = new CoinManager(gameObjects2D);
	gameObjects->push_back(coinManager);
}

void GameScene::setupCarManager()
{
	carManager = new CarManager(gameObjects2D);
	gameObjects->push_back(carManager);
}

void GameScene::setupInput() {
	input = new InputHandler(player);
	gameObjects->push_back(input);
}