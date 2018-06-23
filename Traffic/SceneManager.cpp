#include "SceneManager.h"


GameObject* SceneManager::currentScene;
sf::RenderWindow* SceneManager::window;

void SceneManager::setScene(int sceneId, sf::RenderWindow * window)
{
	SceneManager::window = window;
	SceneManager::setScene(sceneId);
}

void SceneManager::setScene(int sceneId)
{
	delete currentScene;

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