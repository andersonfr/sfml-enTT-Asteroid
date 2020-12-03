#pragma once
#include <SFML/Graphics.hpp>

struct RenderComponent 
{
public:
	sf::Sprite m_sprite;
};

struct Render2dComponent 
{
public:
	sf::VertexArray m_model;
};

struct Render2dSpaceshipComponent
{
	//spaceship is a triangle
	Render2dSpaceshipComponent() 
	{
		m_model[0] = sf::Vector2f(0, 0);
		m_model[1] = sf::Vector2f(15, 0);
		m_model[2] = sf::Vector2f(7.5f, -30);
		m_model[3] = sf::Vector2f(0, 0);
		m_color = sf::Color::White;
	}

	sf::Vector2f m_model[4];
	sf::Color m_color;
};

struct Render2dAsteroidComponent
{
	sf::Vertex m_model[6];
	float m_maxRadius;
	float m_minRadius;

	Render2dAsteroidComponent() {}
};