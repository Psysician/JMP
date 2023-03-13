#include "Engine.h"

#include <string>

void Logic::object_assigned(Object* obj) { }


Body::Body() {
	hitbox_type = None;
}

void Body::tick(double dt, Object* obj)
{
	velocity += gravity*dt;
	obj->position += velocity * dt;
}

Text::Text(const Text& t)
{
	font = t.font;
	text = t.text;
	size = t.size;
	offset = t.offset;
	color = t.color;
}

Text::Text(std::shared_ptr<Font> _font, std::string _text, int _size, ALLEGRO_COLOR _color)
{
	ASSERT(_font);
	font = _font;
	text = _text;
	size = _size;
	color = _color;
}

void Text::draw(Vec2 pos)
{
	font->draw(pos + offset, text.c_str(), size, color);
}

int Text::width()
{
	return al_get_text_width(font->get_al_font(size), text.c_str());
}

