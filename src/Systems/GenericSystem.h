#pragma once

#include <entt.hpp>
#include "../Utils/Utils.h"

class GenericSystem 
{
public:
	GenericSystem(entt::registry& registry) : m_registry(&registry){}
	~GenericSystem() = default;

	virtual void Init(entt::registry* registry);


	virtual void Update(const float deltaTime);
	virtual void Render();
	//we need a reference to the registry
	entt::registry* m_registry;

};