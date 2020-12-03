#pragma once
#include "SFML/Graphics.hpp"


struct TransformComponent 
{
public:
	TransformComponent() {}
	TransformComponent(const sf::Vector2f &p, const sf::Vector2f &s)
	{
		this->position.x = p.x;
		this->position.y = p.y;

		this->scale.x = s.x;
		this->scale.y = s.y;
	}

	sf::Vector2f position;
	sf::Vector2f scale;
};