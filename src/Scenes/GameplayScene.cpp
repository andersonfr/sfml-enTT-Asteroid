#include "GameplayScene.h"
#include "../Components/RenderComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/MovementComponent.h"
#include "../Systems/Render2dSystem.h"
#include "../Systems/Movement2dSystem.h"
#include "../App/SceneManager.h"

void GameplayScene::OnBeginScene()
{
	//add systems
	sf::RenderWindow& window = m_sceneManagerRef->GetWindow();
	m_renderSystems.push_back(std::move(std::make_unique<Render2dSystem>(*m_registry,window)));
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
	sf::Vector2f vel(0.0f, 10.0f);

	m_registry->emplace_or_replace<Render2dSpaceshipComponent>(spaceShipEntity);
	m_registry->emplace_or_replace<TransformComponent>(spaceShipEntity,p,s);
	m_registry->emplace_or_replace<Movement2dComponent>(spaceShipEntity, vel.x,vel.y);
}
