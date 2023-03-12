#include <iostream>

#include "MainMenu.h"

MainMenu::MainMenu()
{
	Object obj;
	obj.sprite.bitmap = al_load_bitmap("image/MainMenu.png");
	obj.body.velocity = Vec2(1.0f, 1.0f);
	if (!obj.sprite.bitmap)
	{
		std::cout << "Error loading image" << std::endl;
		throw 0;
	}
	layers[0].objects.push_back(obj);
}

MainMenu::~MainMenu()
{

}
