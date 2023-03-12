#include "Object.h"


Object::Object()
{

}

void Object::draw()
{

	sprite.draw(position);
}

void Object::tick(double dt)
{
	body.tick(dt, this);
}
