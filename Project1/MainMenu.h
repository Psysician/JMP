#pragma once
#include <allegro5/bitmap_io.h>

#include "Scene.h"
class MainMenu : Scene
{
public:
	MainMenu()
	{
		background = al_load_bitmap("image/MainMenu.png");
	}
};

