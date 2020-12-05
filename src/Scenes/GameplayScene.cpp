#include "GameplayScene.h"
#include "../Components/RenderComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/MovementComponent.h"
#include "../Components/InputComponent.h"
#include "../Systems/Render2dSystem.h"
#include "../Systems/Movement2dSystem.h"
#include "../Systems/PlayerInputSystem.h"
#include "../App/SceneManager.h"

void GameplayScene::OnBeginScene()
{
	m_onPlayerFire.connect<&GameplayScene::SpawnProjectile>(this);

	//add systems
	sf::RenderWindow& window = m_sceneManagerRef->GetWindow();
	m_renderSystems.push_back(std::move(std::make_unique<Render2dSystem>(*m_registry,window)));
	m_logicSystems.push_back(std::move(std::make_unique<PlayerInputSystem>(*m_registry,m_onPlayerFire,window)));
	m_logicSystems.push_back(std::move(std::make_unique<Movement2dSystem>(*m_registry, window)));
	//Create Entities?

	SpawnSpaceShip();
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

	entt::entity asteroidEntity = m_registry->create();
	sf::Vector2 size2 = m_sceneManagerRef->GetWindow().getSize();
	sf::Vector2f p2(size.x / 2.0f, size.y / 2.0f);
	sf::Vector2f s2(1.0f, 1.0f);
	sf::Vector2f vel2(0.0f, 0.0f);

	m_registry->emplace_or_replace<Render2dAsteroidComponent>(asteroidEntity, 25.0f, 50.0f);
	m_registry->emplace_or_replace<TransformComponent>(asteroidEntity, p2, s2);
	m_registry->emplace_or_replace<Movement2dAsteroidComponent>(asteroidEntity, vel2.x, vel2.y);
}

void GameplayScene::SpawnProjectile(float shipAngle, sf::Vector2f shipPosition)
{
	entt::entity projectileEnt = m_registry->create();
	sf::Vector2f vel(sinf(ToRadians(shipAngle)) * 100, -cosf(ToRadians(shipAngle)) * 100);
	sf::Vector2f s(0.5f, 0.5f);
	m_registry->emplace_or_replace<Render2dProjectileComponent>(projectileEnt);
	m_registry->emplace_or_replace<TransformComponent>(projectileEnt, shipPosition,s);
	m_registry->emplace_or_replace<Movement2dProjectileComponent>(projectileEnt, vel.x, vel.y);
}