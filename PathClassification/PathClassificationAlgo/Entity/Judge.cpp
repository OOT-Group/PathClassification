#include "../stdafx.h"
#include "Judge.h"


Judge::Judge()
{
}

std::vector<Route>* Judge::ClassfyRoute(std::vector<Route>& routes)
{
	// ...
	return nullptr;
}

bool Judge::Similar(Point * p1, Point * p2)
{
	double check = p1->CalcDistance(p2);		// 检测点距
	if(check <= distancePara)					// 满足条件
		return true;
	return false;
}

bool Judge::Similar(Route * route1, Route * route2)
{
	double bendRate1 = (route1->GetTotalDistance() / (route1->GetPoints()->at(0).CalcDistance(&route1->GetPoints()->back() ) ) );		// 第一条路径曲度
	double bendRate2 = (route2->GetTotalDistance() / (route2->GetPoints()->at(0).CalcDistance(&route2->GetPoints()->back() ) ) );		// 第二条路径曲度
	if (abs(bendRate1 - bendRate2) <= bendPara)		// 曲度是否在曲度参数范围内
		return true;
	return false;
}

bool Judge::CheckSimilar(Route * route1, Route * route2)
{
	if (Similar(route1, route2))		// 判断两条路径曲度是否在参数范围内
		if (Similar(&route1->GetPoints()->at(0), &route2->GetPoints()->at(0)))		// 判断两条路径的起始点距是否在参数范围内
			if (Similar(&route1->GetPoints()->back(), &route2->GetPoints()->back()))		// 判断两条路径的终止点距是否在参数范围内
				if (Similar(route1->GetCenterPoint(), route2->GetCenterPoint()))					// 判断两条路径的形心点距是否在参数范围内
					return true;
	return false;
}


Judge::~Judge()
{
}
