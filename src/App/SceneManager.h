#pragma once

#include "../Scenes/GameplayScene.h"
#include "../Scenes/MenuScene.h"
#include "../Scenes/EndGameScene.h"

#include <vector>
#include <memory>


class SceneManager 
{
public:	
	void Init(sf::RenderWindow& window, entt::registry& registry);

	Scene& GetCurrentScene() { return *m_currentScene; }
	sf::RenderWindow& GetWindow() const { return *m_window; }

	void ToMenuScene();
	void ToGameplayScene();
	void ToEndGameScene();

	void Update(float deltaTime);
	void Render();

private:

	void ReleaseScene();
	
	Scene* m_currentScene;
	sf::RenderWindow* m_window;

	std::unique_ptr<EndGameScene> m_endGameScene;
	std::unique_ptr<MenuScene> m_menuScene;
	std::unique_ptr<GameplayScene> m_gamplayScene;
};