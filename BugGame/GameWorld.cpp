#include "GameWorld.h"
#include <iostream>
#include <string>
bool GameWorld::Initialise() {

	std::cout << "BugGame: Starting" << std::endl;



	window.create(sf::VideoMode(screenWidth, screenHeight), "Final Year Project : B1032293");

	srand(time(0));

	float rectXDir = 0.1f;
	float rectYDir = 0.1f;

	sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(600, 400);
	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);

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

		window.draw(rectangle);
		
		if (rectangle.getPosition().x > screenWidth - rectangle.getSize().x / 2 || rectangle.getPosition().x < rectangle.getSize().x / 2) {
			rectXDir = rectXDir * -1;
		}		
		if (rectangle.getPosition().y > screenHeight - rectangle.getSize().y / 2 || rectangle.getPosition().y < rectangle.getSize().y / 2) {
			rectYDir = rectYDir * -1;
		}

		rectangle.setPosition(rectangle.getPosition().x + rectXDir, rectangle.getPosition().y + rectYDir);
	
		// Get the window to display its contents
		window.display();

	}
	std::cout << "BugGame: Finished" << std::endl;
	return true;
}