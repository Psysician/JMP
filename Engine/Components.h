#pragma once

#include "Vec2.h"
#include "Font.h"

#include <string>
#include <memory>

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
	Vec2 gravity;
	HitboxType hitbox_type;
	Body();

	void tick(double dt, Object* obj);
};

class Text
{
public:
	std::shared_ptr<Font> font;

	std::string text;
	int size;
	ALLEGRO_COLOR color;
	Vec2 offset;

	Text(const Text& t);
	Text(std::shared_ptr<Font> _font, std::string _text, int _size, ALLEGRO_COLOR _color);

	void draw(Vec2 pos);
	int width();
};
