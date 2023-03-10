#pragma once

//class Shapes
//{
//public:
//	
//
//	bool AABBvsAABB(AABB a, AABB b)
//	{
//		// Exit with no intersection if found separated along an axis 
//		if (a.maxVec.x < b.minVec.x or a.minVec.x > b.maxVec.x) 
//			return false;
//
//
//		if (a.maxVec.y < b.minVec.y or a.minVec.y > b.maxVec.y) 
//			return false;
//				 
//
//		// No separating axis found, therefor there is at least one overlapping axis 
//		return true;
//	}
//};
//
//struct AABB
//{
//	int minVec[2];
//	int maxVec[2];
//};
//