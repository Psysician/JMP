#include <iostream>

#include "MainMenu.h"

class AntLogic : public Logic
{
	struct AntData
	{
		float sim_frames = 0;
	};

public:
	void* allocate() override
	{
		return new AntData();
	}

	virtual void deallocate(void* data) override
	{
		delete (AntData*)data;
	}

	void tick(double dt, Object* obj, void* _data) override
	{
		AntData* data = (AntData*)_data;

		data->sim_frames += dt;
		if (data->sim_frames >= 30.0f)
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

	Object AntOne(Vec2(1000.0f, 50.0f), Vec2(16.0 * 5, 16.0 * 5), logic);
	AntOne.body.velocity = Vec2(-0.5f, 0.0f);
	AntOne.sprite = Sprite("assets/image/antEnemy.png", 2, 0);

	layers[1].objects.push_back(AntOne);

	Object bg;
	bg.sprite = Sprite("assets/image/MainMenu.png");
	bg.size = Vec2(1280.0f, 720.0f);

	layers[0].objects.push_back(bg);


	Object AntSec(Vec2(110.0f, 70.0f), Vec2(-16.0 * 5, 16.0 * 5), logic);
	AntSec.body.velocity = Vec2(+0.5f, 0.0f);
	AntSec.sprite = Sprite("assets/image/antEnemy.png", 2, 0);
	layers[1].objects.push_back(AntSec);

}

MainMenu::~MainMenu()
{

}
