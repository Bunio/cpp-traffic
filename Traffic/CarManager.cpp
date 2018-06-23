#include "CarManager.h"
#include "Files.h"
#include "Properties.h"
#include "SceneManager.h"

CarManager::CarManager(std::list<GameObject2D*>* gameObjects2D)
{
	this->gameObjects2D = gameObjects2D;
	initializeLineCoordinates();
	initializeTextures();
	initializeTimer();
}

void CarManager::initializeLineCoordinates()
{
	lineCoordinates.push_back(Properties::LINE_1_X);
	lineCoordinates.push_back(Properties::LINE_2_X);
	lineCoordinates.push_back(Properties::LINE_3_X);
}


void CarManager::initializeTextures()
{
	std::list<std::string> texturePaths;
	texturePaths.push_back(Files::TEXTURE_CAR_1);
	texturePaths.push_back(Files::TEXTURE_CAR_2);
	texturePaths.push_back(Files::TEXTURE_CAR_3);
	texturePaths.push_back(Files::TEXTURE_CAR_4);
	texturePaths.push_back(Files::TEXTURE_CAR_5);

	for (auto const& texturePath : texturePaths) {
		sf::Texture* texture = new sf::Texture();
		if (!texture->loadFromFile(texturePath)) {
			std::cout << "COULD NOT LOAD CAR TEXTURE";
		}
		carTextures.push_back(texture);
	}

}

void CarManager::initializeTimer()
{
	delayMin = Properties::CAR_MANAGER_DELAY_MIN;
	delayMax = Properties::CAR_MANAGER_DELAY_MAX;
	resetTimer();
}


void CarManager::resetTimer()
{
	currentDelay = Properties::CAR_MANAGER_DELAY_MIN + (std::rand() % (Properties::CAR_MANAGER_DELAY_MAX - Properties::CAR_MANAGER_DELAY_MIN + 1));
}

int CarManager::randomLine()
{
	int lines = lineCoordinates.size();
	int randomLine = currentDelay = 0 + (std::rand() % (lines));
	return lineCoordinates[randomLine];
}
sf::Texture* CarManager::randomTexture()
{
	int textures = lineCoordinates.size();
	int randomTexture = currentDelay = 0 + (std::rand() % (textures));
	return carTextures[randomTexture];
}
int CarManager::randomAmount()
{
	return  Properties::CAR_MANAGER_AMOUNT_MIN + (std::rand() % (Properties::CAR_MANAGER_AMOUNT_MAX - Properties::CAR_MANAGER_AMOUNT_MIN + 1));
}
void CarManager::process(float delta)
{
	currentDelay -= delta;

	if (currentDelay <= 0.0) {
		generateCars();
		resetTimer();

	}
}

std::list<Car*> CarManager::generateCars()
{
	std::list<Car*> newCars;
	int amout = randomAmount();
	for (int i = 0; i < amout; i++) {
		Car* car = new Car(Properties::CAR_SPEED);
		car->setScale(1.0, 1.0);
		car->setTexture(*randomTexture());
		car->setPosition(randomLine() - 20, -Properties::SCENE_HEIGHT / 2 - i * (car->getRealHeight() + 15));
		cars.push_back(car);

		gameObjects2D->push_back(car);
	};

	return newCars;
}

std::list<Car*> CarManager::checkCollision(Player * player)
{
	std::list<Car*> collidedCars;

	// Check which cars collided with player
	for (auto const& car : cars) {
		if (player->getGlobalBounds().intersects(car->getGlobalBounds())) {
			std::cout << "PLAYER-CAR COLLISION";
			collidedCars.push_back(car);
		}
	}

	// Optimize
	if (collidedCars.size() > 0) {
		SceneManager::setScene(3);
	}

	// Remove them from car lists
	//for (auto const& car : collidedCars) {
	//	cars.remove(car);
	//	gameObjects2D->remove(car);
	//}
	return collidedCars;
}
