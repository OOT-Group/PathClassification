#pragma once
#include "Route.h"




class  IClassfyAlgo {
protected:
	double distancePara;
	double bendPara;
public:
	virtual std::vector<Route> ClassfyRoute(std::vector<Route>& routes) = 0;
	void InitPara(double dPara, double bPara) { distancePara = dPara; bendPara = bPara; }
protected:
	virtual bool Similar(Point& p1, Point& p2) = 0;				
	virtual bool Similar(Route& route1, Route& route2) = 0;		
	virtual bool CheckSimilar(Route& route1, Route& route2) = 0;
};