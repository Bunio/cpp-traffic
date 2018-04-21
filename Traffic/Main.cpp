#include <SFML/Graphics.hpp>
#include <iostream>

const int speed = 30;
const int scene_width = 700;
const int scene_height = 1024;

int main()
{
	sf::RenderWindow window(sf::VideoMode(scene_width, scene_height),
		"Hello SFML", sf::Style::Default);

	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	window.setFramerateLimit(60);

	// TEXTURE LOADING ------------------

	sf::Texture roadTexture;
	sf::Texture playerTexture;
	if (!roadTexture.loadFromFile("./road.jpg") & !playerTexture.loadFromFile("./motorbike.png"))
	{
		std::cout << "Error loading image";
	}

	// ROAD ----------------------------

	sf::Sprite road1, road2, player;
	road1.setTexture(roadTexture);
	road2.setTexture(roadTexture);
	int height = road1.getLocalBounds().height;
	road2.setPosition(sf::Vector2f(0.0, -height));

	// PLAYER --------------------------
	player.setTexture(playerTexture);
	player.scale(0.35, 0.35);
	int playerWidth = player.getLocalBounds().width * player.getScale().x;
	int playerHeight = player.getLocalBounds().height * player.getScale().y;
	player.setPosition(scene_width/2 - playerWidth /2, scene_height - playerHeight - 20);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		// INPUT ------------------------------------------

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			player.move(-4, 0);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// left key is pressed: move our character
			player.move(4, 0);
		}
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
		

		// PLAYER ------------------------------------------

		window.draw(player);

		// -------------------------------------------------

		window.display();
	}

	return 0;
}
