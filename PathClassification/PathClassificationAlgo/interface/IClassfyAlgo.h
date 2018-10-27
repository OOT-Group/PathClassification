#pragma once
#include "..\Entity\Route.h"
#include "..\stdafx.h"

class IClassfyAlgo {
protected:
	double distancePara;
	double bendPara;
public:
	virtual std::vector<Route>* ClassfyRoute(const std::vector<Route>& routes) = 0;
	void InitPara(double dPara, double bPara) { distancePara = dPara; bendPara = bPara; }
protected:
	virtual bool Similar(const Point* p1, const Point* p2) = 0;
	virtual bool Similar(const Route* route1, const Route* route2) = 0;
};