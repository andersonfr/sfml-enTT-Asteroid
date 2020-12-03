#include "Movement2dSystem.h"
#include "../Components/TransformComponent.h"
#include "../Components/MovementComponent.h"

void Movement2dSystem::Update(float deltaTime)
{
	m_registry->view<Movement2dComponent, TransformComponent>().each
	([&](auto ship, Movement2dComponent& move, TransformComponent& transform)
		{
			transform.position += move.m_velocity * deltaTime;
			sf::Vector2u windowSize = m_window->getSize();
			if (transform.position.x > windowSize.x) 
			{
				transform.position.x = 0.0f;
			}
			
			if (transform.position.y > windowSize.y) 
			{
				transform.position.y = 0.0f;
			}

			if (transform.position.x < 0.0f)
			{
				transform.position.x = windowSize.x;
			}

			if (transform.position.y < 0.0f)
			{
				transform.position.y = windowSize.y;
			}
		});
}
