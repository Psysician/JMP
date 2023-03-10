#include "Shapes.h"
namespace Shapes
{
	struct AABB
	{
		int minVec[2]; //unten links
		int maxVec[2]; //oben rechts


		static bool AABBvsAABB(AABB a, AABB b)
		{

			if (a.maxVec[0] < b.minVec[0] or a.minVec[0] > b.maxVec[0])
				return false;


			if (a.maxVec[1] < b.minVec[1] or a.minVec[1] > b.maxVec[1])
				return false;

			return true;
		}
	};
}

