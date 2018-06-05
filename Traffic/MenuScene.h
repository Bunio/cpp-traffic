#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include "GameObject.h"
#include "GameObject2D.h"
#include "Button.h"
#include "Files.h"
#include "Properties.h"
#include <SFML/Graphics.hpp>
#include <list>

class MenuScene : public GameObject {
public:
	MenuScene(sf::RenderWindow* window);
	void process(float delta);
private:
	sf::RenderWindow* window;
	Button* newGameBtn;
	void setupButtons();
};

#endif