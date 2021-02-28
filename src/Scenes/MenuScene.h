#pragma once
#include "Scene.h"

class MenuScene : public Scene 
{
public:
	MenuScene(SceneManager& sm, entt::registry& registry) : Scene(&sm, registry) {}
	virtual ~MenuScene() = default;
	void OnBeginScene() override;
	void Update(float deltaTime) override;
	void Render() override;
private:
	sf::Text m_textMenu;
};