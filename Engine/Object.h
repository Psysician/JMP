#pragma once

#include "Vec2.h"
#include "Sprite.h"
#include "Misc.h"

class Object
{
	// components
	Logic* logic;

	size_t data_type;
	void* data;

public:
	Vec2 position;
	Vec2 size;

	// components
	Body body;
	Sprite sprite;
	std::unique_ptr<Text> text;


	Object();
	Object(Vec2 _position, Vec2 _size);
	Object(Logic* _logic);
	Object(Vec2 _position, Vec2 _size, Logic* _logic);
	Object(const Object&);
	~Object();

	void set_logic(Logic* _logic);
	void deallocate_data();
	void draw();
	void tick(double dt);

	template <typename T> void set_data(T _data)
	{
		if (data)
			deallocate_data();

		data = malloc(sizeof(T));
		ASSERT(data);
		*(T*)data = _data;
		data_type = typeid(T).hash_code();
	}

	template <typename T> T* get_data()
	{
		ASSERT(data_type == typeid(T).hash_code());
		return (T*)data;
	}
};

