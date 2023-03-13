#include "Engine.h"

#include <string>

Body::Body() {
	hitbox_type = None;
}

void Body::tick(double dt, Object* obj)
{
	obj->position += velocity * dt;
}


Text::Text(std::string _text)
{
	this->text = _text;
}
