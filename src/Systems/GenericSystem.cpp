#include "GenericSystem.h"

void GenericSystem::Init(entt::registry * registry)
{
	this->m_registry = registry;
}

void GenericSystem::Update(const float deltaTime)
{
}

void GenericSystem::Render()
{
}
