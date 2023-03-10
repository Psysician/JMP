#pragma once

#include <vector>

#include <allegro5/bitmap.h>
#include <allegro5/bitmap_draw.h>

#include "Object.h"

class Layer
{
public:
	std::vector<Object> objects;

	Layer();


	void draw();
	void tick(double dt);
};

class Scene
{
public:
	Layer layers[3];

	Scene();
	~Scene();

	void draw();
	void tick(double dt);
};
