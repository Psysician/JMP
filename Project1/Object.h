#pragma once

#include "Components.h"
#include "Sprite.h"
#include "Vec2.h"

class Object
{
public:
	Vec2 position;
	Body body;
	Sprite sprite;
	Object();
	void draw();
	void tick(double dt);
};

