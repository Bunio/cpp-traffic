#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "GameObject.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include <SFML/Graphics.hpp>

class SceneManager : public GameObject {
public:
	static GameObject* currentScene;
	static void setScene(int sceneId, sf::RenderWindow* window);
	static void setScene(int sceneId);
private:
	static sf::RenderWindow* window;
};

#endif