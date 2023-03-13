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
	load_bitmap(filename);

	frame_count = 1;
	frame = 0;
}

Sprite::Sprite(const char* filename, int _frame_count, int _frame)
{
	load_bitmap(filename);

	frame_count = _frame_count;
	frame = _frame;
}

Sprite::~Sprite()
{
}

void Sprite::draw(Vec2 pos, Vec2 size)
{
	if (!bitmap)
		return;

	float w = (float)(width / frame_count);

	al_draw_scaled_bitmap(bitmap,
		w*frame, 0,						// source x, y
		(float)w, (float)height,		// source w, h
		pos.x, pos.y,					// dest   x, y
		size.x, size.y,					// dest   w, h
		0
	);
}

void Sprite::load_bitmap(const char* filename)
{
	auto bitmap = al_load_bitmap(filename);
	ASSERT(bitmap);
	set_bitmap(bitmap);
}

void Sprite::set_bitmap(ALLEGRO_BITMAP* _bitmap)
{
	DEBUG_ASSERT(_bitmap);
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
