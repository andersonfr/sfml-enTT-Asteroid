#pragma once
#include <SFML/Graphics.hpp>

struct Movement2dShipComponent 
{
	Movement2dShipComponent(float x, float y) : m_velocity(x,y), angle(0.0f), turnDegree(90.0f){}
	sf::Vector2f m_velocity;
	float angle;
	float turnDegree;
};

struct Movement2dAsteroidComponent 
{
	Movement2dAsteroidComponent(float x, float y) : m_velocity(x, y){}
	sf::Vector2f m_velocity;
};
struct Movement2dProjectileComponent 
{
	Movement2dProjectileComponent(float x, float y) : m_velocity(x, y) , m_lifeTime(3.0f){}
	sf::Vector2f m_velocity;
	float m_lifeTime;
};
