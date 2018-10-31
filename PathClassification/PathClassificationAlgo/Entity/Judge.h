#pragma once
#include "../interface/IClassfyAlgo.h"
class Judge :
	public IClassfyAlgo
{
public:
	Judge();
	std::vector<Route>* ClassfyRoute(std::vector<Route>& routes);
	bool Similar(Point* p1, Point* p2);				// 判断两点间距离是否在参数范围内
	bool Similar(Route* route1, Route* route2);		// 判断两路径曲度是否在参数范围内
	bool CheckSimilar(Route* route1, Route* route2);// 判断两路径是否相似
	~Judge();
};

