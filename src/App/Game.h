#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"

class Game 
{
public:

	Game() = default;
	~Game() = default;

	void OnUpdate();
	void OnRender();

	void OnInit();
	void OnEnd();

	void HandleEvents();

private:
	std::unique_ptr<sf::RenderWindow> m_window;
	SceneManager m_sceneManager;
	void SystemsUpdate(float deltaTime);
	entt::registry m_registry;
};