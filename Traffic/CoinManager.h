#ifndef COIN_MANAGER_H
#define COIN_MANAGER_H

#include "GameObject.h"
#include "Coin.h"
#include "Player.h"
#include <list>


class CoinManager : public GameObject {
public:
	CoinManager(std::list<GameObject2D*>* gameObjects2D);
	void process(float delta);
	std::list<Coin*> checkCollision(Player* player);
	std::list<Coin*> generateCoins();
	
private:
	std::list<Coin*> coins;
	std::list<GameObject2D*>* gameObjects2D;
	std::vector<int> lineCoordinates;
	std::vector<sf::Texture> coinTextures;
	void initializeTimer();
	void initializeTextures();
	void initializeLineCoordinates();
	void resetTimer();
	int randomLine();
	int randomAmount();
	int delayMin;
	int delayMax;
	float currentDelay;
};


#endif