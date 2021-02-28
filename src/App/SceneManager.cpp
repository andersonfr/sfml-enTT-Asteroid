#include "SceneManager.h"

void SceneManager::Init(sf::RenderWindow& window, entt::registry& registry)
{
	m_window = &window;

	m_gamplayScene = std::make_unique<GameplayScene>(*this,registry);
	/*m_endGameScene = std::make_unique<EndGameScene>(this,registry);*/
	m_menuScene = std::make_unique<MenuScene>(*this,registry);

	//ToGameplayScene();
	ToMenuScene();
}

void SceneManager::ToMenuScene()
{	
	ReleaseScene();
	m_currentScene = m_menuScene.get();
	m_currentScene->OnBeginScene();
}

void SceneManager::ToGameplayScene()
{
	ReleaseScene();
	m_currentScene = m_gamplayScene.get();
	m_currentScene->OnBeginScene();
}

void SceneManager::ToEndGameScene()
{
	ReleaseScene();
	m_currentScene = m_endGameScene.get();
	m_currentScene->OnBeginScene();
}

void SceneManager::Update(float deltaTime)
{
	if (m_currentScene != nullptr) 
	{
		m_currentScene->Update(deltaTime);
	}
}

void SceneManager::Render()
{
	if (m_currentScene != nullptr) 
	{
		m_currentScene->Render();
	}
}

void SceneManager::ReleaseScene()
{
	if (m_currentScene != nullptr)
	{
		m_currentScene->OnDestroyScene();
	}
}
