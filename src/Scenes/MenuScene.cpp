#include "MenuScene.h"
#include "../App/SceneManager.h"
#include "../Resources/Resources.h"

void MenuScene::OnBeginScene()
{
	sf::RenderWindow& window = m_sceneManagerRef->GetWindow();
	ResourceManager& resourceManager = ResourceManager::GetInstance();
	const sf::Font& fontMenu = resourceManager.GetFont(EFont::Retro);
	m_textMenu.setFont(fontMenu);
	m_textMenu.setFillColor(sf::Color::White);
	m_textMenu.setString("Press Any Key To Start");
	auto textRect = m_textMenu.getLocalBounds();
	m_textMenu.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	 
	m_textMenu.setPosition(window.getSize().x / 2.0f , window.getSize().y / 2);
}

void MenuScene::Update(float deltaTime)
{
	for (int key = -1; key < sf::Keyboard::KeyCount; key++) 
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key)))
		{
			m_sceneManagerRef->ToGameplayScene();
		}
	}
}

void MenuScene::Render()
{
	sf::RenderWindow& window = m_sceneManagerRef->GetWindow();
	window.draw(m_textMenu);
}
