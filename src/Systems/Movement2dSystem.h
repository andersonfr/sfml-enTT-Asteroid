#pragma once
#include "GenericSystem.h"
#include "SFML/Graphics.hpp"

class Movement2dSystem : public GenericSystem 
{
public:
	Movement2dSystem(entt::registry& registry, sf::RenderWindow& window)
		: GenericSystem(registry), m_window(&window) {}
	void Update(float deltaTime) override;
private:
	sf::RenderWindow* m_window;
	void CheckWindowBoundaries(sf::Vector2f& pos);
};
