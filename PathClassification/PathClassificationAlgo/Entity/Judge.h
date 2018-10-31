#pragma once
#include "../interface/IClassfyAlgo.h"
class Judge :
	public IClassfyAlgo
{
public:
	Judge();
	std::vector<Route>* ClassfyRoute(const std::vector<Route>& routes);
	bool Similar(const Point* p1, const Point* p2);				// 判断两点间距离是否在参数范围内
	bool Similar(const Route* route1, const Route* route2);		// 判断两路径曲度是否在参数范围内
	bool CheckSimilar(const Route* route1, const Route* route2);// 判断两路径是否相似
	~Judge();
};

