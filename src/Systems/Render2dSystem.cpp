#include "Render2dSystem.h"
#include "../Components/RenderComponent.h"
#include "../Components/TransformComponent.h"

void Render2dSystem::Render()
{
	//draw spaceship
	m_registry->view<Render2dSpaceshipComponent, TransformComponent>().each
	([&](auto ship, Render2dSpaceshipComponent& render, TransformComponent& transform) 
	{
		size_t size = 4;
		sf::Vector2f p = transform.position;

		sf::Vector2f p1 = p + render.m_model[0];
		sf::Vector2f p2 = p + render.m_model[1];
		sf::Vector2f p3 = p + render.m_model[2];
		sf::Vector2f p4 = p + render.m_model[3];

		sf::Vertex model[4]
		{
			 sf::Vertex(p1, render.m_color),
			 sf::Vertex(p2, render.m_color),
			 sf::Vertex(p3, render.m_color),
			 sf::Vertex(p4, render.m_color)
		};

		m_window->draw(model, size, sf::LinesStrip);
	});
	//draw asteroids
	//TODO

}
