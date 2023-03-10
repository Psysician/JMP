#pragma once
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_draw.h>

class Scene
{
public:
    ALLEGRO_BITMAP* background = nullptr;

    void draw()
    {
        if (background)
        {
            al_draw_bitmap(background, 0, 0, 0);
        }
    }
};
