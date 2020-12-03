#pragma once
#include <SFML/Graphics.hpp>

struct Movement2dComponent 
{
	Movement2dComponent(float x, float y) : m_velocity(x,y){}
	sf::Vector2f m_velocity;
};