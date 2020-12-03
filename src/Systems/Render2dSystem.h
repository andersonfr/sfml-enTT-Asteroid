#pragma once
#include "GenericSystem.h"
#include "SFML/Graphics.hpp"

class Render2dSystem : public GenericSystem 
{
public:
	Render2dSystem(entt::registry& registry, sf::RenderWindow& window) 
		: GenericSystem(registry), m_window(&window) {}

	void Render() override;
private:
	sf::RenderWindow* m_window;
};