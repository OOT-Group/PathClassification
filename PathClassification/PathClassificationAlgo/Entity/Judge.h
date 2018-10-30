#pragma once
#include "../interface/IClassfyAlgo.h"
class Judge :
	public IClassfyAlgo
{
public:
	Judge();
	std::vector<Route>* ClassfyRoute(const std::vector<Route>& routes);
	bool Similar(const Point* p1, const Point* p2);
	bool Similar(const Route* route1, const Route* route2);
	~Judge();
};

