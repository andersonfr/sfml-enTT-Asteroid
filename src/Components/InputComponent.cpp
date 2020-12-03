#pragma once
#include "SFML/Graphics.hpp"

struct Input2dComponent 
{
	Input2dComponent() {}

	sf::Keyboard::Key upKey;
	sf::Keyboard::Key leftKey;
	sf::Keyboard::Key rightKey;
	sf::Keyboard::Key downKey;
};