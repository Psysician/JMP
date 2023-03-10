#include <iostream>

#include "MainMenu.h"

MainMenu::MainMenu()
{
	Object obj;
	obj.sprite.bitmap = al_load_bitmap("image/MainMenu.png");
	if (!obj.sprite.bitmap)
	{
		std::cout << "Error loading image" << std::endl;
		throw 0;
	}
	layers[0].objects.push_back(obj);
}
