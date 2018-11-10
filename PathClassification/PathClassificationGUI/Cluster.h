#pragma once
#include "Route.h"
#include <vector>
class  Cluster
{
private:
	std::vector<Route> routes;
	Point avgCenterPoint;
	Point avgStartPoint;
	Point avgEndPoint;
public:
	Cluster();
	void SetRoutes(std::vector<Route>& routes) { this->routes = routes; }
	std::vector<Route>& GetRoutes() { return routes; }

	void SetCenterPoint(Point &point) { this->avgCenterPoint = point; }
	Point& GetCenterPoint() { return avgCenterPoint; }

	void GetStartPoint(Point &point) { this->avgStartPoint = point; }
	Point& GetStartPoint() { return avgStartPoint; }

	void SetEndPoint(Point &point) { this->avgEndPoint = point; }
	Point& GetEndPoint() { return avgEndPoint; }

	double CalcRouteToClusterDistance(Route& route);

	Point CalcAvgStartPoint();
	Point CalcAvgCenterPoint();
	Point CalcAvgEndPoint();

	~Cluster();
};

