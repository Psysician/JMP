#pragma once
#include "Vec2.h"

#include <string>

class Object;

class Logic
{
public:
	virtual void object_assigned(Object* obj);
	virtual void tick(double dt, Object* obj) = 0;
};

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

