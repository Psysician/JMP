#include "Engine.h"

#include <string>

void* Logic::allocate()
{
	return nullptr;
}

void Logic::deallocate(void* data) { }

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
