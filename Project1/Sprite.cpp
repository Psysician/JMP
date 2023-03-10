#include "Sprite.h"

Sprite::Sprite()
{
	bitmap = nullptr;
}

Sprite::~Sprite()
{
}

void Sprite::draw(Vec2 pos)
{
	if (bitmap)
		al_draw_bitmap(bitmap, pos.x, pos.y, 0);
}
