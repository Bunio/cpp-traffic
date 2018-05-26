#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "GameScene.h"
#include "Properties.h"

int main()
{
	// TODO: Use camera
	sf::RenderWindow window(sf::VideoMode(Properties::SCENE_WIDTH, Properties::SCENE_HEIGHT),"Traffic", sf::Style::Default);
	window.setFramerateLimit(60);

	GameScene gameScene(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)window.close();

		window.clear();
		gameScene.process(2.0);
		window.display();
	}

	return 0;
}
