#pragma once

#include <allegro5/allegro.h>

#include "Vec2.h"


class Sprite
{
public:
	ALLEGRO_BITMAP* bitmap;

	Sprite();
	~Sprite();

	void draw(Vec2 pos);
};

