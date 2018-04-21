#include <SFML/Graphics.hpp>
#include <iostream>

const int speed = 15;
const int scene_width = 640;
const int scene_height = 1024;

int main()
{
	sf::RenderWindow window(sf::VideoMode(scene_width, scene_height),
		"Hello SFML", sf::Style::Default);

	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	sf::Texture texture;
	if (!texture.loadFromFile("./road.jpg"))
	{
		std::cout << "Error loading image";
	}
	sf::Sprite sprite1, sprite2;
	sprite1.setTexture(texture);
	sprite2.setTexture(texture);

	int height = sprite1.getLocalBounds().height;
	sprite2.setPosition(sf::Vector2f(0.0, -height));

	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		sprite1.move(sf::Vector2f(0, speed));
		sprite2.move(sf::Vector2f(0, speed));
		window.draw(sprite1);
		window.draw(sprite2);

		if (sprite1.getPosition().y >= scene_height) {
			sprite1.setPosition(sf::Vector2f(0, sprite2.getPosition().y - height));
		}
		if (sprite2.getPosition().y >= scene_height) {
			sprite2.setPosition(sf::Vector2f(0, sprite1.getPosition().y - height));
		}
		window.display();
	}

	return 0;
}
