#include "Scene.h"//im grunde world bzw alles was man gerade braucht

Layer::Layer()
{
	objects.reserve(5);
}

void Layer::draw()
{
	for (size_t i = 0; i < objects.size(); i++)
	{
		objects[i].draw();
	}
}

void Layer::tick(double dt)
{

}


Scene::Scene()
{
}

Scene::~Scene()
{

}

void Scene::draw()
{
	for (int i = 0; i < 3; i++)
	{
		layers[i].draw();
	}
}

void Scene::tick(double dt)
{
	for (int i = 0; i < 3; i++)
	{
		layers[i].tick(dt);
	}
}
