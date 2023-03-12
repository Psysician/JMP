#include <iostream>

#include "MainMenu.h"

MainMenu::MainMenu()
{
	Object obj;
	obj.sprite = Sprite("image/MainMenu.png");
	obj.size = Vec2(1280.0, 720.0);
	//obj.body.velocity = Vec2(1.0f, 1.0f);
	layers[0].objects.push_back(obj);
}

MainMenu::~MainMenu()
{

}
