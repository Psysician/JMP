#include <iostream>

#include "MainMenu.h"

class AntLogic : public Logic
{
	struct AntData
	{
		float sim_frames;

		AntData() : sim_frames(0) {}
	};

public:
	void object_assigned(Object* obj) override
	{
		obj->set_data(AntData());
	}

	void tick(double dt, Object* obj) override
	{
		AntData* data = obj->get_data<AntData>();

		data->sim_frames += dt;
		if (data->sim_frames >= 0.35f)
		{
			obj->sprite.frame += 1;
			obj->sprite.frame %= obj->sprite.frame_count;
			data->sim_frames = 0.0f;
		}
	}
};

MainMenu::MainMenu()
{
	Logic* logic = new AntLogic();

	Object ant_one(Vec2(100.0, 50.0), Vec2(-16 * 4, 16 * 4), logic);
	ant_one.sprite = Sprite("assets/image/antEnemy.png", 2, 0);
	ant_one.body.velocity = Vec2(25.0, 0.0);
	layers[1].objects.push_back(ant_one);

	Object ant_sec(Vec2(1000.0, 300.0), Vec2(16 * 4, 16 * 4), logic);
	ant_sec.sprite = Sprite("assets/image/antEnemy.png", 2, 0);
	ant_sec.body.velocity = Vec2(-25.0, 0.0);
	layers[1].objects.push_back(ant_sec);


	Object bg;
	bg.sprite = Sprite("assets/image/MainMenu.png");
	bg.size = Vec2(1280.0f, 720.0f);
	layers[0].objects.push_back(bg);


	auto font = Font::load("assets/slkscr.ttf");
	ASSERT(font);

	Text text = Text(
		font,
		std::string("Yote"),
		50,
		al_map_rgb(237, 47, 206)
	);

	Object title(Vec2(1280.0 / 2.0 - text.width() / 2 - 10.0, 150.0f), Vec2(0, 0));
	title.text = std::make_unique<Text>(
		text
	);
	layers[0].objects.push_back(title);
}

MainMenu::~MainMenu()
{

}
