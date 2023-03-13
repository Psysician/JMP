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


Text::Text(std::string _text)
{
	this->text = _text;
}
