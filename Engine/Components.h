#pragma once
#include "Vec2.h"

#include <string>

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

class Text
{
	std::string text;
public:
	float size;

	Text(std::string _text);
};

