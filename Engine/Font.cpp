#include "Engine.h"

Font::Font(const char* _filename) {
    filename = _filename;
}


Font::~Font()
{
    for (auto& it : cache)
    {
        al_destroy_font(it.second);
    }
}

std::shared_ptr<Font> Font::load(const char* filename)
{
    return std::make_shared<Font>(Font(filename));
}

ALLEGRO_FONT* builtin = nullptr;

ALLEGRO_FONT* Font::get_al_font(int size)
{
    // find in cache
    auto entry = cache.find(size);
    if (entry != cache.end())
        return entry->second;

    // otherwise, load from disk
    auto n = al_load_font(filename, size, 0);
    ASSERT(n);
    cache.insert(std::pair<int, ALLEGRO_FONT*>(size, n));
    return n;
}

void Font::draw(Vec2 pos, const char* text, int size, ALLEGRO_COLOR color)
{
    ALLEGRO_FONT* font = get_al_font(size);

    al_draw_text(font, color, pos.x, pos.y, 0, text);
}

