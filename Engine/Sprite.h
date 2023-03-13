#pragma once

#include <allegro5/allegro.h>

#include "Engine.h"


class Sprite
{
	ALLEGRO_BITMAP* bitmap;
	int width;
	int height;

public:
	int frame_count;
	int frame;

	Sprite();
	Sprite(Sprite& sprite);
	Sprite(const char* filename);
	Sprite(const char* filename, int _frame_count, int _frame);
	~Sprite();

	void draw(Vec2 pos, Vec2 size);
	void load_bitmap(const char* filename);
	void set_bitmap(ALLEGRO_BITMAP* bitmap);
	ALLEGRO_BITMAP* get_bitmap();
	Vec2 get_size();
};

