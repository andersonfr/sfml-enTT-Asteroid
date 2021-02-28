#pragma once
#include "GenericSystem.h"
#include "SFML/Graphics.hpp"

class PlayerInputSystem : public GenericSystem 
{
public :
	PlayerInputSystem(entt::registry& registry, entt::delegate<void(float, sf::Vector2f)>& onFireDelegate ,sf::RenderWindow& window)
		: GenericSystem(registry), m_onFireDelegate(onFireDelegate),m_window(&window) , m_fireRate(0.2f),m_fireCoolDown(m_fireRate) {}
	void Update(float deltaTime) override;
private:
	entt::delegate<void(float, sf::Vector2f)>& m_onFireDelegate;
	sf::RenderWindow* m_window;
	float m_fireRate;
	float m_fireCoolDown;
};
