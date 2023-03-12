#pragma once
#include <allegro5/display.h>
#include "Scene.h"

class Game
{
public:
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* eventqueue;

	bool running;
	Scene* current_scene;

	Game();
	~Game();

	void process_events();
	void run();
	void draw();
	void tick(double dt);
};

