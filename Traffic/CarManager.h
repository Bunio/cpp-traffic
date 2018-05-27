#ifndef CAR_MANAGER_H
#define CAR_MANAGER_H

#include "GameObject.h"
#include "Car.h"
#include "Player.h"
#include <list>


class CarManager : public GameObject {
public:
	CarManager(std::list<GameObject2D*>* gameObjects2D);
	void process(float delta);
	std::list<Car*> checkCollision(Player* player);
	std::list<Car*> generateCars();

private:
	std::list<Car*> cars;
	std::list<GameObject2D*>* gameObjects2D;
	std::vector<int> lineCoordinates;
	std::vector<sf::Texture*> carTextures;
	void initializeTimer();
	void initializeTextures();
	void initializeLineCoordinates();
	void resetTimer();
	int randomLine();
	sf::Texture* randomTexture();
	int randomAmount();
	int delayMin;
	int delayMax;
	float currentDelay;
};
#endif