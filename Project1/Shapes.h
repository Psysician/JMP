#pragma once
#include "Vec2.h"
namespace Shapes
{
	class AABB
	{
	public:
		Vec2 min; //unten links
		Vec2 max; //oben rechts

		static bool AABBvsAABB(AABB a, AABB b);
	};

	class Circle
	{
		float radius;
		Vec2 position;
	};
}