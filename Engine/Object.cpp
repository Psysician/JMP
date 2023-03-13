#include "Engine.h"

#include <typeinfo>

Object::Object()
{
	logic = nullptr;
	data_type = typeid(void).hash_code();
	data = nullptr;
}
Object::Object(Vec2 _position, Vec2 _size)
{
	logic = nullptr;
	data_type = typeid(void).hash_code();
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
	if (data)
		deallocate_data();
}

void Object::set_logic(Logic* _logic)
{
	logic = _logic;

	if (logic)
		logic->object_assigned(this);
}

void Object::deallocate_data()
{
	free(data);
}

void Object::draw()
{
	sprite.draw(position, size);
}

void Object::tick(double dt)
{
	if (logic)
		logic->tick(dt, this);
	body.tick(dt, this);
}
