#pragma once
#include "GenericSystem.h"
#include "SFML/Graphics.hpp"

class Collision2dSystem : public GenericSystem 
{
public:
	Collision2dSystem(entt::registry& registry, entt::delegate<void(sf::Vector2f, sf::Vector2f)>& onAsteroidDestroyed)
		: GenericSystem(registry), m_onAsteroidDestroyed(onAsteroidDestroyed) {}
	void Update(float deltaTime) override;
	entt::delegate<void(sf::Vector2f, sf::Vector2f)> m_onAsteroidDestroyed;
};