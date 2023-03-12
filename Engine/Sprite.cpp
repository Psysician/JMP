#include "Engine.h"

Sprite::Sprite()
{
	bitmap = nullptr;
	width = 0;
	height = 0;

	frame_count = 1;
	frame = 0;
}

Sprite::Sprite(Sprite& sprite)
{
	set_bitmap(sprite.bitmap);

	frame_count = 1;
	frame = 0;
}

Sprite::Sprite(const char* filename)
{
	set_bitmap(al_load_bitmap(filename));

	frame_count = 1;
	frame = 0;

	ALLEGRO_ASSERT(bitmap);
}

Sprite::~Sprite()
{
}

void Sprite::draw(Vec2 pos, Vec2 size)
{
	if (!bitmap)
		return;

	if (frame_count == 1 && frame == 0)
		al_draw_scaled_bitmap(bitmap,
			0, 0,							// source x, y
			(float)width, (float)height,	// source w, h
			pos.x, pos.y,					// dest   x, y
			size.x, size.y,					// dest   w, h
			0
		);
	else
	{

	}
}

void Sprite::set_bitmap(ALLEGRO_BITMAP* _bitmap)
{
	if (!_bitmap)
		throw "Error loading image";
	this->bitmap = _bitmap;
	width = al_get_bitmap_width(_bitmap);
	height = al_get_bitmap_height(_bitmap);
}

ALLEGRO_BITMAP* Sprite::get_bitmap()
{
	return this->bitmap;
}

Vec2 Sprite::get_size()
{
	if (!bitmap)
		return Vec2(0, 0);

	float w = (float)al_get_bitmap_width(bitmap);
	float h = (float)al_get_bitmap_height(bitmap);

	return Vec2(w, h);
}
