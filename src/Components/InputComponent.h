#pragma once

#include "SFML/Graphics.hpp"

struct Input2dComponent
{
	Input2dComponent(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key right, sf::Keyboard::Key left
		, sf::Keyboard::Key fire)
	{
		upKey = up;
		downKey = down;
		rightKey = right;
		leftKey = left;
		fireKey = fire;
	}

	sf::Keyboard::Key upKey;
	sf::Keyboard::Key leftKey;
	sf::Keyboard::Key rightKey;
	sf::Keyboard::Key downKey;
	
	sf::Keyboard::Key fireKey;

};

struct InputMovementComponent 
{
	InputMovementComponent() {}
};