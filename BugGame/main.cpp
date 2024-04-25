//SFML documentation: https://www.sfml-dev.org/learn.php
#include "Game.h"

int main()
{
	Game game;
	while (!game.GetWindow()->IsDone()) {
		game.Update();
		game.Render();
		game.LateUpdate();
	}
	return 0;
}
