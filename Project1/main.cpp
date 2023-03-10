#include <iostream>

#include "LivingObject.h"
#include "MainMenu.h"
#include "Game.h"


int main()
{
	Game game = Game();
	game.current_scene = (Scene*) new MainMenu();
	game.run();
	return 0;
}


//bool coolison_check()
//{
//	Object anyobjects;
//	LivingObject player;
//	
//	if (
//		player.x < anyobjects.x + anyobjects.w &&
//		player.x + player.w > anyobjects.x &&
//		player.y < anyobjects.y + anyobjects.h &&
//		player.h + player.y > anyobjects.y
//		) {
//		
//		return true;
//	}
//	else {
//		return false;
//	}
//
//}