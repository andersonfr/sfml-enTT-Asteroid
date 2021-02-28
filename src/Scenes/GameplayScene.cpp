#include "GameplayScene.h"
#include "../Components/RenderComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/MovementComponent.h"
#include "../Components/InputComponent.h"
#include "../Components/CollisionComponent.h"
#include "../Systems/Render2dSystem.h"
#include "../Systems/Movement2dSystem.h"
#include "../Systems/PlayerInputSystem.h"
#include "../Systems/Collision2dSystem.h"
#include "../App/SceneManager.h"

void GameplayScene::OnBeginScene()
{
	m_onPlayerFire.connect<&GameplayScene::SpawnProjectile>(this);
	m_onAsteroidDestroyed.connect <&GameplayScene::OnAsteroidExploded>(this);
	//add systems
	sf::RenderWindow& window = m_sceneManagerRef->GetWindow();
	m_logicSystems.push_back(std::move(std::make_unique<PlayerInputSystem>(*m_registry,m_onPlayerFire,window)));
	m_logicSystems.push_back(std::move(std::make_unique<Movement2dSystem>(*m_registry, window)));
	m_logicSystems.push_back(std::move(std::make_unique<Collision2dSystem>(*m_registry,m_onAsteroidDestroyed)));
	m_renderSystems.push_back(std::move(std::make_unique<Render2dSystem>(*m_registry,window)));
	//Create Entities?

	SpawnSpaceShip();
	SpawnAsteroids(20,25.0f,50.0f);
}

void GameplayScene::OnDestroyScene()
{
	//Destroy Entities?
	m_registry->clear();
}

void GameplayScene::Update(float deltaTime)
{
	for (auto& p : m_logicSystems)
	{
		p->Update(deltaTime);
	}
}

void GameplayScene::Render()
{
	for (auto& p : m_renderSystems) 
	{
		p->Render();
	}
}

void GameplayScene::SpawnSpaceShip()
{
	entt::entity spaceShipEntity = m_registry->create();
	//positioning the spaceship at window's center

	sf::Vector2 size = m_sceneManagerRef->GetWindow().getSize();
	sf::Vector2f p(size.x / 2.0f, size.y / 2.0f);
	sf::Vector2f s(1.0f, 1.0f);
	sf::Vector2f vel(0.0f, 0.0f);

	m_registry->emplace_or_replace<Render2dSpaceshipComponent>(spaceShipEntity);
	m_registry->emplace_or_replace<TransformComponent>(spaceShipEntity,p,s);
	m_registry->emplace_or_replace<Movement2dShipComponent>(spaceShipEntity, vel.x,vel.y);
	m_registry->emplace_or_replace<Input2dComponent>(
		spaceShipEntity,
		sf::Keyboard::Up,
		sf::Keyboard::Down,
		sf::Keyboard::Right,
		sf::Keyboard::Left,
		sf::Keyboard::Space);
}

void GameplayScene::SpawnProjectile(float shipAngle, sf::Vector2f shipPosition)
{
	entt::entity projectileEnt = m_registry->create();
	sf::Vector2f vel(sinf(ToRadians(shipAngle)) * 100, -cosf(ToRadians(shipAngle)) * 100);
	sf::Vector2f s(0.5f, 0.5f);
	m_registry->emplace_or_replace<TransformComponent>(projectileEnt, shipPosition,s);
	m_registry->emplace_or_replace<Movement2dProjectileComponent>(projectileEnt, vel.x, vel.y);
	m_registry->emplace_or_replace<Projectile2dCollisionComponent>(projectileEnt);
	m_registry->emplace_or_replace<Render2dProjectileComponent>(projectileEnt);
}

void GameplayScene::SpawnAsteroids(int number, float minRadius, float maxRadius)
{
	sf::Vector2 size = m_sceneManagerRef->GetWindow().getSize();
	sf::Rect<float> window = sf::Rect<float>(0.0f, 0.0f, size.x, size.y);

	for (int i = 0; i < number; i++)
	{
		entt::entity asteroidEntity = m_registry->create();
		sf::Vector2f p{ RandomRange(window.left, window.width), RandomRange(window.top, window.height) };
		sf::Vector2f s{ 1.0f, 1.0f };
		sf::Vector2f vel{ RandomRange(10.0f, 20.0f), RandomRange(-10.0f, 10.0f) };
		m_registry->emplace_or_replace<Render2dAsteroidComponent>(asteroidEntity, minRadius, maxRadius);
		m_registry->emplace_or_replace<TransformComponent>(asteroidEntity, p, s);
		m_registry->emplace_or_replace<Movement2dAsteroidComponent>(asteroidEntity, vel.x, vel.y);
	}
}

void GameplayScene::OnAsteroidExploded(sf::Vector2f pos,sf::Vector2f vel)
{
	float minRadius, maxRadius;

	minRadius = 10.0f;
	maxRadius = minRadius * 2;
	sf::Vector2f v;
	float speed = VectorLength(vel.x, vel.y) * 1.5f;
	for (int i = 0; i < 2; i++)
	{
		entt::entity asteroidEntity = m_registry->create();
		sf::Vector2f s(1.0f, 1.0f);
		/*sf::Vector2f vel(RandomRange(10.0f, 20.0f), RandomRange(-10.0f, 10.0f));*/
		v.x = (vel.x * cos(ToRadians(90)) - vel.y * sin(ToRadians(90))) * (1 - 2*(i));
		v.y = (vel.x * sin(ToRadians(90)) + vel.y * cos(ToRadians(90))) * (1 - 2 * (i));
		NormalizeVector(v.x, v.y);
		v.x *= speed;
		v.y *= speed;
		m_registry->emplace_or_replace<Render2dAsteroidComponent>(asteroidEntity, minRadius, maxRadius);
		m_registry->emplace_or_replace<TransformComponent>(asteroidEntity, pos, s);
		m_registry->emplace_or_replace<Movement2dAsteroidComponent>(asteroidEntity, v.x,v.y);
	}
}
