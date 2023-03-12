#pragma once

#include "Components.h"
#include "Sprite.h"
#include "Vec2.h"

class Object
{
public:
	Vec2 position;
	Vec2 size;

	Body body;
	Sprite sprite;

	Object();
	Object(const Object&);

	void draw();
	void tick(double dt);
};

