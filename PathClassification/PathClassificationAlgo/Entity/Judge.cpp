#include "../stdafx.h"
#include "Judge.h"


Judge::Judge()
{
}

std::vector<Route>* Judge::ClassfyRoute(const std::vector<Route>& routes)
{
	return nullptr;
}

bool Judge::Similar(const Point * p1, const Point * p2)
{
	double check = p1->CalcDistance(p2);		// ¼ì²âµã¾à
	if(check <= distancePara)					// Âú×ãÌõ¼þ
		return true;
	return false;
}

bool Judge::Similar(const Route * route1, const Route * route2)
{
	return false;
}


Judge::~Judge()
{
}
