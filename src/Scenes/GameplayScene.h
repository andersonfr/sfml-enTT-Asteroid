#pragma once
#include "Scene.h"


class GameplayScene : public Scene 
{
public:
	GameplayScene(SceneManager& sm,entt::registry& registry) : Scene(&sm,registry) {}
	virtual ~GameplayScene() = default;
	void OnBeginScene() override;
	void OnDestroyScene() override;
	void Update(float deltaTime) override;
	void Render() override;
private:
	void SpawnSpaceShip();
	void SpawnProjectile(float shipAngle, sf::Vector2f shipPos);
	void SpawnAsteroids(int number, float minRadius, float maxRadius);
	void OnAsteroidExploded(sf::Vector2f pos , sf::Vector2f vel);
	entt::delegate<void(float,sf::Vector2f)> m_onPlayerFire{};
	entt::delegate<void(sf::Vector2f, sf::Vector2f)> m_onAsteroidDestroyed{};
};