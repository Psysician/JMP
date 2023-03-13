#include <iostream>

#include "Engine.h"

#include "MainMenu.h"


int main()
{
	Game game = Game();
	game.current_scene = (Scene*) new MainMenu();
	game.run();
	return 0;
}


