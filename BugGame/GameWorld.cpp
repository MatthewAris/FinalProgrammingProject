#include "GameWorld.h"
#include <iostream>
#include <string>
bool GameWorld::Initialise() {

	std::cout << "BugGame: Starting" << std::endl;

	window.create(sf::VideoMode(800, 600), "Final Year Project : B1032293");

	srand(time(0));

	// Main loop that continues until we call window.close()
	while (window.isOpen())
	{
		// Handle any pending SFML events		
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		// We must clear the window each time around the loop
		window.clear();

		// Get the window to display its contents
		window.display();

		std::cout << "BugGame: Finished" << std::endl;
	}
}