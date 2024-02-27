#pragma once
// SFML header file for graphics, there are also ones for Audio, Window, System and Network
#include <SFML/Graphics.hpp>

class GameWorld
{
public:
	bool Initialise();

private:
	// Create an instance of the SFML RenderWindow type which represents the display
	// and initialise its size and title text
	//sf::RenderWindow window(sf::VideoMode(800, 600), "Final Year Project : B1032293");	

	sf::RenderWindow window;

	int screenWidth{ 800 };
	int screenHeight{ 600 };
};

