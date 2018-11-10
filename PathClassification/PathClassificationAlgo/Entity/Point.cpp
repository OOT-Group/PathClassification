#include "..\stdafx.h"
#include "Point.h"

#define DLL_EXPORT
Point::Point()
{
}


double Point::CalcDistance(Point& p)
{
	return sqrt(((double)this->x - p.x) * ((double)this->x - p.x)
		+ ((double)this->y - p.y) * ((double)this->y - p.y));
}


Point::~Point()
{
}
