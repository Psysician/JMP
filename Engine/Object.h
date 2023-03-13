#pragma once

#include "Components.h"
#include "Sprite.h"
#include "Vec2.h"

class Object
{
	// components
	Logic* logic;
	void* data;

public:
	Vec2 position;
	Vec2 size;
	// components
	
	Body body;
	Sprite sprite;

	Object();
	Object(Vec2 _position, Vec2 _size);
	Object(Logic* _logic);
	Object(Vec2 _position, Vec2 _size, Logic* _logic);
	Object(const Object&);
	~Object();

	void set_logic(Logic* _logic);
	void draw();
	void tick(double dt);
};

