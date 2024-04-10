//SFML documentation: https://www.sfml-dev.org/learn.php
#include "GameWorld.h"

int main()
{
	GameWorld game;
	while (!game.GetWindow()->IsDone()) {
		game.HandleInput();
		game.Update();
		game.Render();
		//sf::sleep(sf::seconds(0.1));
		game.RestartClock();
	}
	return 0;
}
