#pragma once
#include "entt.hpp"
#include "SFML/Graphics.hpp"
#include "../Systems/GenericSystem.h"

class SceneManager;

class Scene 
{
public:

	Scene(SceneManager* sm, entt::registry& registry) 
		: m_sceneManagerRef(sm), m_registry(&registry) {}
	~Scene() = default;

	virtual void OnBeginScene() {}
	virtual void OnDestroyScene() {}
	virtual void Update(float deltaTime) {}
	virtual void Render() {}
	SceneManager* m_sceneManagerRef;
	entt::registry* m_registry;
	std::vector<std::unique_ptr<GenericSystem>> m_renderSystems;
	std::vector<std::unique_ptr<GenericSystem>> m_logicSystems;
};