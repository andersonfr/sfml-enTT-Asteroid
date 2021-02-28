#include "Movement2dSystem.h"
#include "../Components/TransformComponent.h"
#include "../Components/MovementComponent.h"
#include "../Components/InputComponent.h"

void Movement2dSystem::Update(float deltaTime)
{
	m_registry->view<Movement2dAsteroidComponent, TransformComponent>().each
	([&](auto asteroid, Movement2dAsteroidComponent& move, TransformComponent& transform)
		{
			transform.position += move.m_velocity * deltaTime;
			CheckWindowBoundaries(transform.position);
		}
	);

	m_registry->view<Movement2dShipComponent, TransformComponent>().each
	([&](auto asteroid, Movement2dShipComponent& move, TransformComponent& transform)
		{
			transform.position += move.m_velocity * deltaTime;
			CheckWindowBoundaries(transform.position);
		}
	);

	m_registry->view<Movement2dProjectileComponent, TransformComponent>().each
	([&](auto projectile, Movement2dProjectileComponent& move, TransformComponent& transform)
		{
			transform.position += move.m_velocity * deltaTime;
			move.m_lifeTime -= deltaTime;
			if (move.m_lifeTime < 0.0f)
			{
				m_registry->destroy(projectile);
			}
			CheckWindowBoundaries(transform.position);
		}
	);
}

void Movement2dSystem::CheckWindowBoundaries(sf::Vector2f & pos)
{
	sf::Vector2u windowSize = m_window->getSize();
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
