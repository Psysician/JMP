#include "Components.h"

#include "Object.h"

Body::Body() {
	hitbox_type = None;
}

void Body::tick(double dt, Object* obj)
{
	obj->position += velocity * dt;
}
