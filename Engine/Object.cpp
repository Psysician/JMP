#include "Engine.h"


Object::Object()
{
	logic = nullptr;
	data = nullptr;
}
Object::Object(Vec2 _position, Vec2 _size)
{
	logic = nullptr;
	data = nullptr;

	position = _position;
	size = _size;
}
Object::Object(Logic* _logic)
{
	logic = nullptr;
	data = nullptr;

	set_logic(_logic);
}

Object::Object(const Object& o)
{
	position = o.position;
	size = o.size;

	logic = o.logic;
	data = nullptr;
	set_logic(o.logic);
	body = o.body;
	sprite = o.sprite;
}

Object::Object(Vec2 _position, Vec2 _size, Logic* _logic)
{
	position = _position;
	size = _size;
	set_logic(_logic);
}

Object::~Object()
{
	// deallocate data
	if (logic && data)
		logic->deallocate(data);
}

void Object::set_logic(Logic* _logic)
{
	// deallocate old data if present
	if (logic && data)
		logic->deallocate(data);

	logic = _logic;
	// allocate new data
	if (_logic)
		data = logic->allocate();
}

void Object::draw()
{
	sprite.draw(position, size);
}

void Object::tick(double dt)
{
	if (logic)
		logic->tick(dt, this, data);
	body.tick(dt, this);
}
