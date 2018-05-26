#include <SFML/Graphics.hpp>
#include <iostream>
#include "Files.h"
#include "PlayerClass.cpp"

const int speed = 50;
const int scene_width = 700;
const int scene_height = 1024;

int main()
{

	// TODO: Use camera

	sf::RenderWindow window(sf::VideoMode(scene_width, scene_height),
		"Hello SFML", sf::Style::Default);

	sf::Font font;
	font.loadFromFile(Files::FONT_ARIAL);

	window.setFramerateLimit(60);

	// TEXTURE LOADING ------------------

	sf::Texture roadTexture;
	sf::Texture playerTexture;

	if (!roadTexture.loadFromFile(Files::TEXTURE_ROAD) & !playerTexture.loadFromFile(Files::TEXTURE_MOTORBIKE))
	{
		std::cout << "Error loading image";
	}

	// ROAD ----------------------------

	sf::Sprite road1, road2;
	road1.setTexture(roadTexture);
	road2.setTexture(roadTexture);
	int height = road1.getLocalBounds().height;
	road2.setPosition(sf::Vector2f(0.0, -height));

	PlayerClass playerClass;
	GameObject* player = &playerClass;

	// PLAYER --------------------------
	playerClass.setTexture(playerTexture);
	playerClass.scale(0.35, 0.35);
	int playerWidth = playerClass.getRealWidth();
	int playerHeight = playerClass.getRealHeight();
	playerClass.setPosition(scene_width/2 - playerWidth /2, scene_height - playerHeight - 20);

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
	
		road1.move(sf::Vector2f(0, speed));
		road2.move(sf::Vector2f(0, speed));
		window.draw(road1);
		window.draw(road2);

		if (road1.getPosition().y >= scene_height) {
			road1.setPosition(sf::Vector2f(0, road2.getPosition().y - height));
		}
		if (road2.getPosition().y >= scene_height) {
			road2.setPosition(sf::Vector2f(0, road1.getPosition().y - height));
		}
		

		//input->handleInput(2.0);
		player->process(2.0);
		//playerClass.process(2.0);
		window.draw(playerClass);

		// -------------------------------------------------

		window.display();
	}

	return 0;
}
