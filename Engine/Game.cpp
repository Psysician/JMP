#include "Engine.h"

#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include <allegro5/keyboard.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>


void initialize_allegro()
{
	// initialize allegro
	ASSERT(al_init());

	// install features
	ASSERT(al_install_keyboard());

	// initialize addons
	ASSERT(al_init_image_addon());
	ASSERT(al_init_font_addon());
	ASSERT(al_init_ttf_addon());
	ASSERT(al_init_primitives_addon());
}

void uninitialize_allegro()
{
	// shutdown addons
	al_shutdown_image_addon();
	al_shutdown_font_addon();
	al_shutdown_ttf_addon();
	al_shutdown_primitives_addon();

	// uninstall features
	al_uninstall_keyboard();

	// uninstall allegro
	al_uninstall_system();
}

unsigned int Game::instances = 0;

Game::Game()
{
	// only initialize allegro once
	if (Game::instances == 0)
		initialize_allegro();
	Game::instances += 1;

	// create display
	display = al_create_display(1280, 720);
	ASSERT(display);

	// create event queue
	eventqueue = al_create_event_queue();

	// register event sources
	al_register_event_source(eventqueue, al_get_keyboard_event_source());
	al_register_event_source(eventqueue, al_get_display_event_source(display));


	running = true;
	current_scene = nullptr;
}

Game::~Game()
{
	// destroy items
	al_destroy_display(display);
	al_destroy_event_queue(eventqueue);

	// only uninitialize allegro once
	Game::instances -= 1;
	if (Game::instances == 0)
		uninitialize_allegro();
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

const ALLEGRO_COLOR bgrcolor = al_map_rgb(0, 0, 0);
const double TARGET_DT = 1.0/250.0;
 
void Game::run()
{
	double cur_time = al_get_time();

	while (running)
	{
		double new_time = al_get_time();
		// time passed since last frame
		double frame_time = new_time - cur_time;
		cur_time = new_time;

		// one tick should not exceed TARGET_DT
		while (frame_time >= TARGET_DT)
		{
			tick(TARGET_DT);
			frame_time -= TARGET_DT;
		}

		// tick for the remaining time
		tick(frame_time);

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

