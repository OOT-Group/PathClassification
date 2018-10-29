#include "..\stdafx.h"
#include "Point.h"


Point::Point()
{
}


double Point::CalcDistance(Point pA, Point pB)
{
	return sqrt(((double)pB.x - pA.x) * ((double)pB.x - pA.x)                     
		+ ((double)pB.y - pA.y) * ((double)pB.y - pA.y));                              
}

Point::~Point()
{
}
