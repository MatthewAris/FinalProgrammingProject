//SFML documentation: https://www.sfml-dev.org/learn.php
#include "GameWorld.h"

int main()
{
	GameWorld* gameWorld = new GameWorld;
	if (!gameWorld->Initialise())
		delete gameWorld;
	
	return 0;
}
