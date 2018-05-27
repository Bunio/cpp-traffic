#include "RoadManager.h"
#include "Road.h"
#include "Files.h"
#include "Properties.h"
#include <list>


RoadManager::RoadManager()
{
	buildRoads();
	roadHeight = road1.getLocalBounds().height;
	road2.setPosition(sf::Vector2f(0.0, -roadHeight));
}

void RoadManager::process(float delta)
{

	if (road1.getPosition().y >= Properties::SCENE_HEIGHT) {
		road1.setPosition(sf::Vector2f(0, road2.getPosition().y - roadHeight));
	}
	if (road2.getPosition().y >= Properties::SCENE_HEIGHT) {
		road2.setPosition(sf::Vector2f(0, road1.getPosition().y - roadHeight));
	}

	road1.process(delta);
	road2.process(delta);
}

std::vector<Road*> RoadManager::getRoads()
{
	std::vector<Road*> roads;
	roads.push_back(&road1);
	roads.push_back(&road2);
	return roads;
}

void RoadManager::buildRoads()
{
	road1.loadTexture(Files::TEXTURE_ROAD);
	road1.setSpeed(50);
	road2.loadTexture(Files::TEXTURE_ROAD);
	road2.setSpeed(50);
}