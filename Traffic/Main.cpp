#include <SFML/Graphics.hpp>
#include <iostream>
#include "Files.h"
#include "Road.h"
#include "Properties.h"
#include "Player.h"
#include "InputHandler.h"
#include <list>



const int speed = 50;


int main()
{
	
	std::vector<GameObject*> gameObjects;

	// TODO: Use camera
	sf::RenderWindow window(sf::VideoMode(Properties::SCENE_WIDTH, Properties::SCENE_HEIGHT),"Traffic", sf::Style::Default);
	window.setFramerateLimit(60);


	// ROAD ----------------------------

	Road road1, road2;
	road1.loadTexture(Files::TEXTURE_ROAD);
	road2.loadTexture(Files::TEXTURE_ROAD);
	road1.setSpeed(speed);
	road2.setSpeed(speed);
	int height = road1.getLocalBounds().height;
	road2.setPosition(sf::Vector2f(0.0, -height));

	Player player;
	InputHandler input(&player);
	GameObject* pp = &player;

	
	gameObjects.push_back(&road1);
	gameObjects.push_back(&road2);
	gameObjects.push_back(&player);

	// PLAYER --------------------------
	player.loadTexture(Files::TEXTURE_MOTORBIKE);

	player.scale(0.35, 0.35);
	int playerWidth = player.getRealWidth();
	int playerHeight = player.getRealHeight();
	player.setPosition(Properties::SCENE_WIDTH/2 - playerWidth /2, Properties::SCENE_HEIGHT - playerHeight - 20);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		// ROAD -------------------------------------------
	

		if (road1.getPosition().y >= Properties::SCENE_HEIGHT) {
			road1.setPosition(sf::Vector2f(0, road2.getPosition().y - height));
		}
		if (road2.getPosition().y >= Properties::SCENE_HEIGHT) {
			road2.setPosition(sf::Vector2f(0, road1.getPosition().y - height));
		}
		

		for (int i = 0; i < gameObjects.size(); i++) {
			gameObjects[i]->process(2.0);
			window.draw(*gameObjects[i]);
		}

		input.handleInput(2.0);
		// -------------------------------------------------

		window.display();
	}

	return 0;
}
