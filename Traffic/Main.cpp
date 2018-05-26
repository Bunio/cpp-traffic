#include <SFML/Graphics.hpp>
#include <iostream>
#include "Files.h"
#include "Road.h"
#include "RoadManager.h"
#include "Properties.h"
#include "Player.h"
#include "InputHandler.h"
#include <list>



const int speed = 50;


int main()
{
	
	std::vector<GameObject2D*> gameObjects2D;
	std::vector<GameObject*> gameObjects;

	// TODO: Use camera
	sf::RenderWindow window(sf::VideoMode(Properties::SCENE_WIDTH, Properties::SCENE_HEIGHT),"Traffic", sf::Style::Default);
	window.setFramerateLimit(60);


	Player player;
	RoadManager roadManager;
	InputHandler input(&player);
	
	gameObjects.push_back(&player);
	gameObjects.push_back(&roadManager);
	
	gameObjects2D.push_back(roadManager.getRoads()[0]);
	gameObjects2D.push_back(roadManager.getRoads()[1]);
	gameObjects2D.push_back(&player);

	// PLAYER --------------------------
	player.loadTexture(Files::TEXTURE_MOTORBIKE);
	player.scale(0.35, 0.35);
	int playerWidth = player.getRealWidth();
	int playerHeight = player.getRealHeight();
	player.setPosition(Properties::SCENE_WIDTH/2 - playerWidth /2, Properties::SCENE_HEIGHT - playerHeight - 20);
	// -------------------------------------


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)window.close();

		
		window.clear();

		for (int i = 0; i < gameObjects.size(); i++) {
			gameObjects[i]->process(2.0);
		}
		for (int i = 0; i < gameObjects2D.size(); i++) {
			gameObjects2D[i]->process(2.0);
			window.draw(*gameObjects2D[i]);
		}
		
		
		input.handleInput(2.0);
		window.display();
	}

	return 0;
}

/*
void processGameObjects(std::vector<GameObject*> gameObjects) {
	for (int i = 0; i < gameObjects.size(); i++)
		gameObjects[i]->process(2.0);
}

void drawGameObjects(std::vector<GameObject2D*> gameObjects2D, sf::RenderWindow* window) {
	for (int i = 0; i < gameObjects2D.size(); i++)
		window->draw(*gameObjects2D[i]);
}
*/