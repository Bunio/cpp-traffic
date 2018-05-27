#include "CoinManager.h"
#include "Files.h"
#include "Properties.h"

void CoinManager::process(float delta)
{
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

	// Remove them from LOCAL coin list (Does not remove from game scene)
	for (auto const& coin : collidedCoins) coins.remove(coin);
	
	return collidedCoins;
}

std::list<Coin*> CoinManager::generateCoins()
{
	std::list<Coin*> newCoins;

	for (int i = 0; i < 10; i++) {
		Coin* coin = new Coin(1);
		coin->scale(0.1, 0.1);
		coin->loadTexture(Files::TEXTURE_COIN);
		coin->setPosition(Properties::LINE_1_X, 50 - i * (coin->getRealWidth() +  10));
		coins.push_back(coin);
		newCoins.push_back(coin);
	};

	return newCoins;
}
