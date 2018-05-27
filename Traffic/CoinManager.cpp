#include "CoinManager.h"
#include "Files.h"
#include "Properties.h"

CoinManager::CoinManager(std::list<GameObject2D*>* gameObjects2D)
{
	this->gameObjects2D = gameObjects2D;
	initializeLineCoordinates();
	initializeTextures();
	initializeTimer();
}

void CoinManager::initializeLineCoordinates()
{
	lineCoordinates.push_back(Properties::LINE_1_X);
	lineCoordinates.push_back(Properties::LINE_2_X);
	lineCoordinates.push_back(Properties::LINE_3_X);
}


void CoinManager::initializeTextures()
{
	sf::Texture texture;
	if (!texture.loadFromFile(Files::TEXTURE_COIN)) {
		std::cout << "COULD NOT LOAD COIN TEXTURE";
	}
	coinTextures.push_back(texture);
}

void CoinManager::initializeTimer()
{
	delayMin = Properties::COIN_MANAGER_DELAY_MIN;
	delayMax = Properties::COIN_MANAGER_DELAY_MAX;
	resetTimer();
}


void CoinManager::resetTimer()
{
	currentDelay = Properties::COIN_MANAGER_DELAY_MIN + (std::rand() % (Properties::COIN_MANAGER_DELAY_MAX - Properties::COIN_MANAGER_DELAY_MIN + 1));
}

int CoinManager::randomLine()
{
	int lines = lineCoordinates.size();
	int randomLine = currentDelay = 0 + (std::rand() % (lines));
	return lineCoordinates[randomLine];
}
int CoinManager::randomAmount()
{
	return  Properties::COIN_MANAGER_AMOUNT_MIN + (std::rand() % (Properties::COIN_MANAGER_AMOUNT_MAX - Properties::COIN_MANAGER_AMOUNT_MIN + 1));
}
void CoinManager::process(float delta)
{
	currentDelay -= delta;

	if (currentDelay <= 0.0) {
		generateCoins();
		resetTimer();

	}
}

std::list<Coin*> CoinManager::generateCoins()
{
	std::list<Coin*> newCoins;
	int randomLineCoordinates = randomLine();
	int amout = randomAmount();
	for (int i = 0; i < amout; i++) {
		Coin* coin = new Coin(Properties::COIN_SPEED);
		coin->scale(0.1, 0.1);
		coin->setTexture(coinTextures[0]);
		coin->setPosition(randomLineCoordinates, -Properties::SCENE_HEIGHT/2 - i * (coin->getRealWidth() +  10));
		coins.push_back(coin);
		
		gameObjects2D->push_back(coin);
	};

	return newCoins;
}

std::list<Coin*> CoinManager::checkCollision(Player * player)
{
	std::list<Coin*> collidedCoins;

	// Check which coins collided with player
	for (auto const& coin : coins) {
		if (player->getGlobalBounds().intersects(coin->getGlobalBounds())) {
			coin->collect();
			collidedCoins.push_back(coin);
		}
	}

	// Remove them from coin lists
	for (auto const& coin : collidedCoins) {
		coins.remove(coin);
		gameObjects2D->remove(coin);
	}
	return collidedCoins;
}
