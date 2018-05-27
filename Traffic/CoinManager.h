#ifndef COIN_MANAGER_H
#define COIN_MANAGER_H

#include "GameObject.h"
#include "Coin.h"
#include "Player.h"
#include <list>


class CoinManager : public GameObject {
public:
	void process(float delta);
	std::list<Coin*> checkCollision(Player* player);
	std::list<Coin*> generateCoins();
	
private:
	std::list<Coin*> coins;

};


#endif