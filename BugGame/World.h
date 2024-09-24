#pragma once
#include <SFML/Graphics.hpp>

class World
{
public:
	World() {};
	World(sf::Vector2u l_windSize);
	~World();
	
	void Update();
	void Render(sf::RenderWindow& l_window);

private:
	sf::Vector2u m_windowSize;

};

