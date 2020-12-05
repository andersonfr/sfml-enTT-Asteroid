#include "Game.h"

void Game::OnInit()
{
	//TODO
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "Asteroid Game");
	m_window->getSize();
	
	m_sceneManager.Init(*m_window,m_registry);

	OnUpdate();
}

void Game::OnEnd()
{
	m_registry.clear();
	//m_sceneManager
	m_window->close();
}

void Game::HandleEvents()
{
	sf::Event event;
	//handle system events
	while (m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			OnEnd();	
		}
		if (event.type == sf::Event::KeyPressed) 
		{
			int x = 0;
		}
	}
}

void Game::OnUpdate()
{
	sf::Clock clock;
	while (m_window->isOpen()) 
	{
		sf::Time dt = clock.restart();
		HandleEvents();
		SystemsUpdate(dt.asSeconds());
		OnRender();
	}
}

void Game::SystemsUpdate(float deltaTime)
{
	m_sceneManager.Update(deltaTime);
}

void Game::OnRender()
{
	m_window->clear();
	m_sceneManager.Render();
	m_window->display();
}

