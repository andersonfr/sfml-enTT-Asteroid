#include <SFML/Graphics.hpp>

int main() 
{
	
	sf::RenderWindow window (sf::VideoMode(1366, 768, 32U), "SFML RUNNING");
	sf::CircleShape shape(sf::CircleShape(10));

	shape.setFillColor(sf::Color::Blue);
	
	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}
		window.clear();
		window.draw(shape);
		window.display();
	}
	
	return 0;
}