#pragma once
#include "Scene.h"


class GameplayScene : public Scene 
{
public:
	GameplayScene(SceneManager& sm,entt::registry& registry) : Scene(&sm,registry) {}
	~GameplayScene() = default;
	void OnBeginScene() override;
	void OnDestroyScene() override;
	void Update(float deltaTime) override;
	void Render() override;
private:
	void SpawnSpaceShip();
};