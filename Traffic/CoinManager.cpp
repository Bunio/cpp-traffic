#include "CoinManager.h"
#include "Files.h"
#include "Properties.h"

void CoinManager::process(float delta)
{
}

std::vector<Coin*> CoinManager::generateCoins()
{
	std::vector<Coin*> newCoins;

	for (int i = 0; i < 10; i++) {
		Coin* coin = new Coin(1);
		coin->scale(0.1, 0.1);
		coin->loadTexture(Files::TEXTURE_COIN);
		coin->setPosition(Properties::LINE_1_X, 50 - i * (coin->getRealWidth() +  10));
		newCoins.push_back(coin);
	};

	return newCoins;
}
