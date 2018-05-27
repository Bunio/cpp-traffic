#ifndef COIN_MANAGER_H
#define COIN_MANAGER_H

#include "GameObject.h"
#include "Coin.h"
#include <list>


class CoinManager : public GameObject {
public:
	void process(float delta);
	std::vector<Coin*> generateCoins();
private:
	std::vector<Coin*> coins;

};


#endif