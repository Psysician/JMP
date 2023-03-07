#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include <allegro5/keyboard.h>
#include <allegro5/allegro_image.h>

class Scene;
class MainMenu;

bool initallegro()
{    
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon())

        return false;

    return true;
}


int oscheck()
{
    return 1;
}

int main()
{
    
   
    if (!initallegro())
    {
	    switch (oscheck())
	    {
	    case 1:
            std::cout << "ERROR INIT ALLEGRO 5" << std::endl;
            return 1;

	    //case 2: mac

	    //case 3: linux

	    default:
            printf("ERROR INIT ALLEGRO 5");
		    
	    }        

    }

    ALLEGRO_COLOR bgrcolor = al_map_rgb(0, 0, 0);

    ALLEGRO_DISPLAY* display = al_create_display(1280, 720);

    ALLEGRO_EVENT_QUEUE* eventqueue = al_create_event_queue();

    ALLEGRO_EVENT event;
    
	al_register_event_source(eventqueue, al_get_keyboard_event_source());

    al_register_event_source(eventqueue, al_get_display_event_source(display));

    Scene* current = new MainMenu();

    while (true)
    {
        if (al_get_next_event(eventqueue, &event))
        {
	        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	        {
                break;
	        }

        }
        
        al_clear_to_color(bgrcolor);
        
        al_flip_display();

    }    
    al_destroy_display(display);
    al_destroy_event_queue(eventqueue);

	return 0;
}

class Object
{    
public:
    float x = 0;
    float y = 0;
    float w = 0;
    float h = 0;

};

class LivingObject : public Object
{
public:

};

class Player : LivingObject
{
};

class Scene
{
public:
    ALLEGRO_BITMAP* background = nullptr;

    void draw()
    {
        if(background)
        {
	        al_draw_bitmap(background, 0, 0, 0);
        }        
    }
    
};

class MainMenu : Scene
{
public:
	MainMenu()
	{
        background = al_load_bitmap("image/MainMenu.png");
	}
};

bool coolison_check()
{
    Object anyobjects;
    LivingObject player;


    if (
        player.x < anyobjects.x + anyobjects.w &&
        player.x + player.w > anyobjects.x &&
        player.y < anyobjects.y + anyobjects.h &&
        player.h + player.y > anyobjects.y
        ) {
        
        return true;
    }
    else {
        return false;
    }

}