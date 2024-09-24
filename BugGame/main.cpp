//SFML documentation: https://www.sfml-dev.org/learn.php
#include "Game.h"

void main(int argc, void** argv[])
{
	Game game;
	while (!game.GetWindow()->IsDone()) {
		game.Update();
		game.Render();
		game.LateUpdate();
	}
}
