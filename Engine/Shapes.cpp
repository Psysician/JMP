#include "Engine.h"

namespace Shapes
{
	bool AABB::AABBvsAABB(AABB a, AABB b)
	{
		return (a.min.x < b.max.x && a.max.x > b.min.x) &&
			(a.min.y < b.max.y && a.max.y > b.min.y);
	}

	bool Circle::circlevscircle(Circle a, Circle b)
	{
		Vec2 diff = a.center - b.center;
		if (diff.lenght() < a.radius + b.radius)
		{
			return true;
		}
		return false;
	}

	bool Circle::cricletouch(Circle a, Circle b)
	{
		// broken?
		if (Vec2::dotproduct(a.center - b.center, a.center - b.center) < a.radius * b.radius)
		{
			return true;
		}
		return false;
	}
}

