#include "Engine.h"


Object::Object()
{

}

Object::Object(const Object& o)
{
	position = o.position;
	size = o.size;
	body = o.body;
	sprite = o.sprite;
}

void Object::draw()
{
	sprite.draw(position, size);
}

void Object::tick(double dt)
{
	body.tick(dt, this);
}
