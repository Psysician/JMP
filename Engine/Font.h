#pragma once
#include <memory>
#include <unordered_map>

#include <allegro5/allegro_font.h>

class Font
{
	const char* filename;
	std::unordered_map<int, ALLEGRO_FONT*> cache;

	Font(const char* _filename);


public:
	ALLEGRO_FONT* get_al_font(int size);
	~Font();

	static std::shared_ptr<Font> load(const char* filename);
	void draw(Vec2 pos, const char* text, int size, ALLEGRO_COLOR color);
};

