#include "PlayerInputSystem.h"
#include "../Components/InputComponent.h"
#include "../Components/MovementComponent.h"
#include "../Components/TransformComponent.h"

void PlayerInputSystem::Update(float deltaTime)
{
	sf::Event event;
	m_registry->view<Input2dComponent, Movement2dShipComponent, TransformComponent>().each
	([&](auto ent, Input2dComponent& input, Movement2dShipComponent& movement, TransformComponent& transform)
	{
		if (sf::Keyboard::isKeyPressed(input.upKey)) 
		{
			float angle = movement.angle;
			float angleRad = ToRadians(angle);
			sf::Vector2f thrust{ sinf(angleRad), -cosf(angleRad) };
			thrust *= 50 * deltaTime;
			movement.m_velocity += thrust;
		}

		if (sf::Keyboard::isKeyPressed(input.downKey)) 
		{
			float angle = movement.angle;
			float angleRad = angle * M_PIl / 180.0f;
			sf::Vector2f thrust{ sinf(angleRad), -cosf(angleRad) };
			thrust *= -10 * deltaTime;
			movement.m_velocity += thrust;
		}

		if (sf::Keyboard::isKeyPressed(input.rightKey)) 
		{
			movement.angle += movement.turnDegree * deltaTime;
		}

		if (sf::Keyboard::isKeyPressed(input.leftKey))
		{
			movement.angle -= movement.turnDegree * deltaTime;
		}
		
		if (sf::Keyboard::isKeyPressed(input.fireKey))
		{
			if (m_fireCoolDown < 0.0f)
			{
				if (m_onFireDelegate)
				{
					sf::Vector2f pos ( transform.position.x, transform.position.y);
					m_onFireDelegate(movement.angle,pos);
				}
				m_fireCoolDown = m_fireRate;
			}
		}

		m_fireCoolDown -= deltaTime;
	});
}
