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
	double check = p1->CalcDistance(p2);		// 检测点距
	if(check <= distancePara)					// 满足条件
		return true;
	return false;
}

bool Judge::Similar(const Route * route1, const Route * route2)
{
	std::vector<Point>* points = route1->GetPoints();		
	std::vector<Point>* _points = route2->GetPoints();
	double bendRate1 = (route1->GetTotalDistance / (points->at(0).CalcDistance(points->back() ) ) );		// 第一条路径曲度
	double bendRate2 = (route2->GetTotalDistance / (_points->at(0).CalcDistance(_points->back() ) ) );		// 第二条路径曲度
	if (abs(bendRate1 - bendRate2) <= bendPara)		// 曲度是否在曲度参数范围内
		return true;
	return false;
}

bool Judge::CheckSimilar(const Route * route1, const Route * route2)
{
	std::vector<Point>* points = route1->GetPoints();
	std::vector<Point>* _points = route2->GetPoints();
	if (Similar(route1, route2))		// 判断两条路径曲度是否在参数范围内
		if (Similar(points->at(0), _points->at(0)))		// 判断两条路径的起始点距是否在参数范围内
			if (Similar(points->back(), _points->back()))		// 判断两条路径的终止点距是否在参数范围内
				if (Similar(route1->GetCenterPoint(), route2->GetCenterPoint()))		// 判断两条路径的形心点距是否在参数范围内
					return true;
	return false;
}


Judge::~Judge()
{
}
