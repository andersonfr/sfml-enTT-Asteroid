#include "Render2dSystem.h"
#include "../Components/RenderComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/MovementComponent.h"


void Render2dSystem::Render()
{
	//draw spaceship
	m_registry->view<Render2dSpaceshipComponent, TransformComponent, Movement2dShipComponent>().each
	([&](auto ship, Render2dSpaceshipComponent& render, TransformComponent& transform, Movement2dShipComponent& movement)
	{
		int size = 3;
		sf::Vector2f p = transform.position;
		//rotate model
		sf::Vector2f rotate[3];
		float angle = movement.angle;
		float angleRad = ToRadians(angle);
		for (int i = 0; i < size; i++) 
		{
			rotate[i].x = render.m_model[i].x * cosf(angleRad) - render.m_model[i].y * sinf(angleRad);
			rotate[i].y = render.m_model[i].x * sinf(angleRad) + render.m_model[i].y * cosf(angleRad);
		}
		//translate model
		sf::Vector2f translate[3];
		for (int i = 0; i < size; i++)
		{
			translate[i] = p + rotate[i];
		}
		//draw model
		sf::Vertex model[2];
		for (int i = 0; i < size; i++)
		{
			model[0] = sf::Vertex(translate[i], render.m_color);
			model[1] = sf::Vertex(translate[(i + 1) % size], render.m_color);
			m_window->draw(model, 2, sf::Lines);
		}
	});
	//draw asteroids	
	m_registry->view<Render2dAsteroidComponent, TransformComponent, Movement2dAsteroidComponent>().each
	([&](auto asteroid, Render2dAsteroidComponent& render, TransformComponent& transform, Movement2dAsteroidComponent& movement)
	{
			int size = 20;
			sf::Vector2f p = transform.position;
			//rotate model
			sf::Vector2f rotate[20];
			float angle = 18.0f;
			
			for (int i = 0; i < size; i++)
			{
				float angleRad = ToRadians(angle * i);
				rotate[i].x = render.m_model[i].x * cosf(angleRad) - render.m_model[i].y * sinf(angleRad);
				rotate[i].y = render.m_model[i].x * sinf(angleRad) + render.m_model[i].y * cosf(angleRad);
			}
			//translate model
			sf::Vector2f translate[20];
			for (int i = 0; i < size; i++)
			{
				sf::Vector2f pos = p + rotate[i];
				//CheckWindowBoundaries(pos, *m_window);
				translate[i] = pos;
			}

			//draw model
			sf::Vertex model[2];
			for (int i = 0; i < size; i++)
			{
				model[0] = sf::Vertex(translate[i], render.m_color);
				model[1] = sf::Vertex(translate[(i + 1) % size], render.m_color);
				m_window->draw(model, 2, sf::LinesStrip);
			}

	});
	//draw bullets
	m_registry->view<Render2dProjectileComponent, TransformComponent, Movement2dProjectileComponent>().each
	([&](auto projectile, Render2dProjectileComponent& render, TransformComponent& transform, Movement2dProjectileComponent& move)
	{
		sf::Vector2f p = transform.position;
		/*if (move.m_lifeTime > 0.0f) */
		{
			render.m_bullet.setPosition(p);
			render.m_bullet.setSize(transform.scale);
			render.m_bullet.setFillColor(sf::Color::Black);
			render.m_bullet.setOutlineThickness(1.0f);
			render.m_bullet.setOutlineColor(sf::Color::White);
			m_window->draw(render.m_bullet);
		}
	});
}

void CheckWindowBoundaries(sf::Vector2f & pos, sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();
	if (pos.x > windowSize.x)
	{
		pos.x -= windowSize.x;
	}

	if (pos.y > windowSize.y)
	{
		pos.y -= windowSize.y;
	}

	if (pos.x < 0.0f)
	{
		pos.x += windowSize.x;
	}

	if (pos.y < 0.0f)
	{
		pos.y += windowSize.y;
	}
}