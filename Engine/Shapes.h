#pragma once
#include "Vec2.h"
namespace Shapes
{
	class AABB
	{
	public:
		Vec2 min; //unten links
		Vec2 max; //oben rechts
		Vec2 center;
		static bool AABBvsAABB(AABB a, AABB b);
	};

	class Circle
	{
	public:
		float radius;
		Vec2 center;

		static bool circlevscircle(Circle a, Circle b);
		static bool cricletouch(Circle a, Circle b);
	};
}