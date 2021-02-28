#include "Collision2dSystem.h"
#include "../Components/CollisionComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/RenderComponent.h"
#include "../Components/MovementComponent.h"

void Collision2dSystem::Update(float deltaTime)
{
	m_registry->view<Projectile2dCollisionComponent,TransformComponent, Render2dProjectileComponent, Movement2dProjectileComponent>().each
	([&](auto proj, TransformComponent& projTransform, Render2dProjectileComponent& projRender, Movement2dProjectileComponent& move)
		{
			
			m_registry->view<Render2dAsteroidComponent, TransformComponent, Movement2dAsteroidComponent>().each
			([&, projTransform, proj](auto asteroid, Render2dAsteroidComponent& astRender, TransformComponent& astTransform, Movement2dAsteroidComponent& astMove)
			{
				sf::Vector2f vector = (projTransform.position - astTransform.position);
				float distance = sqrtf(vector.x * vector.x + vector.y * vector.y);
				int asteroidSize = astRender.m_size;

				if (distance < astRender.m_maxRadius)
				{
					if (m_onAsteroidDestroyed &&  asteroidSize >= 40)
						m_onAsteroidDestroyed(astTransform.position, astMove.m_velocity);
					m_registry->destroy(proj);
					m_registry->destroy(asteroid);
				}
			});
		}
	);
}
