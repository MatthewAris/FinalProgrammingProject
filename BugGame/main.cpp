//SFML documentation: https://www.sfml-dev.org/learn.php
#include "Game.h"

int main()
{
	Game game;
	while (!game.GetWindow()->IsDone()) {
		game.HandleInput();
		game.Update();
		game.Render();
		//sf::sleep(sf::seconds(0.1));
		game.RestartClock();
	}
	return 0;
}
