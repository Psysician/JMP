#pragma once
#include "Vec2.h"

class Object;

enum HitboxType
{
	None,
	Rectangular,
	Circular,
	Triangle,
};

class Body
{
public:
	Vec2 velocity;
	HitboxType hitbox_type;

	Body();

	void tick(double dt, Object* obj);
};

