#include "..\stdafx.h"
#include "Point.h"


Point::Point()
{
}


double Point::CalcDistance(const Point* p)const
{
	return sqrt(((double)this->x - p->x) * ((double)this->x - p->x)
		+ ((double)this->y - p->y) * ((double)this->y - p->y));
}


Point::~Point()
{
}
