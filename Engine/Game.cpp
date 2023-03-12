#include "Engine.h"

#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>


Game::Game()
{
	ALLEGRO_ASSERT(al_init());
	al_install_keyboard();
	al_init_image_addon();

	display = al_create_display(1280, 720);
	eventqueue = al_create_event_queue();
	current_scene = nullptr;

	al_register_event_source(eventqueue, al_get_keyboard_event_source());
	al_register_event_source(eventqueue, al_get_display_event_source(display));

	running = true;
}

Game::~Game()
{
	al_destroy_display(display);
	al_destroy_event_queue(eventqueue);
}


void Game::process_events()
{
	ALLEGRO_EVENT event;

	if (al_get_next_event(eventqueue, &event))
	{
		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			running = false;
		}
	}
}

ALLEGRO_COLOR bgrcolor = al_map_rgb(0, 0, 0);

const double TARGET_DT = 0.01;

void Game::run()
{
	double cur_time = al_get_time();
	double accumulator = 0.0;

	while (running)
	{
		double new_time = al_get_time();
		double frame_time = new_time - cur_time;
		cur_time = new_time;

		accumulator += frame_time;

		while (accumulator >= TARGET_DT)
		{
			tick(1.0);
			accumulator -= TARGET_DT;
		}

		tick(accumulator * (1.0 / TARGET_DT));
		accumulator = 0.0;


		process_events();
		draw();
	}

}

void Game::draw()
{
	al_clear_to_color(bgrcolor);
	
	if (current_scene)
		current_scene->draw();
	
	al_flip_display();
}

void Game::tick(double dt)
{
	if (current_scene)
		current_scene->tick(dt);
}

