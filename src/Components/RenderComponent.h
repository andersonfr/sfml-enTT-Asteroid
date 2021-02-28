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
		m_model[0] = sf::Vector2f(0, -7.5f);
		m_model[1] = sf::Vector2f(-3.75f, 7.5f);
		m_model[2] = sf::Vector2f(3.75f, 7.5f);
		m_color = sf::Color::White;
	}

	sf::Vector2f m_model[3];
	sf::Color m_color;
};

struct Render2dAsteroidComponent
{
	Render2dAsteroidComponent(float minRadius, float maxRadius)  
	{
		m_size = 0;
		for (int i = 0; i < 20; i++) 
		{
			m_minRadius = minRadius;
			m_maxRadius = maxRadius;
			float radius = RandomRange(minRadius, maxRadius);
			m_size = radius > m_size ? radius : m_size;
			m_model[i] = sf::Vector2f{ radius, 0.0f};

		}
		m_color = sf::Color::White;
	}
	
	sf::Vector2f m_model[20];
	sf::Color m_color;
	float m_maxRadius;
	float m_minRadius;
	int m_size;
};

struct Render2dProjectileComponent 
{
	Render2dProjectileComponent() 
	{
		m_bullet.setSize(sf::Vector2f(1.0f, 1.0f));
	}

	sf::RectangleShape m_bullet;
};