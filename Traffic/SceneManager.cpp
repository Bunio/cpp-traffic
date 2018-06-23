#include "SceneManager.h"


GameObject* SceneManager::currentScene;

void SceneManager::setScene(int sceneId, sf::RenderWindow * window)
{
	switch (sceneId) {
		case 1:
			currentScene = new MenuScene(window); 
			break;
		case 2:
			currentScene = new GameScene(window);
			break;
		case 3:
			currentScene = new GameOverScene(window);
			break;
	}
}
