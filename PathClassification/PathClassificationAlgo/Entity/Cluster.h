#pragma once
#include "Route.h"
#include <vector>
class Cluster
{
private:
	std::vector<Route> routes;
	Point* centerPoint;
	Point* stratPoint;
	Point* endPoint;
public:
	Cluster();
	void SetRoutes(std::vector<Route>& routes) { this->routes = routes; }
	std::vector<Route>* GetRoutes() { return &routes; }

	void SetCenterPoint(Point* point) { this->centerPoint = point; }
	Point* GetCenterPoint() { return centerPoint; }

	void SetStratPoint(Point* point) { this->stratPoint = point; }
	Point* GetStratPoint() { return stratPoint; }

	void SetEndPoint(Point* point) { this->endPoint = point; }
	Point* GetEndPoint() { return endPoint; }

	double CalcRouteToClusterDistance(const Route& route);

	Point* CalcAvgStartPoint();
	Point* CalcAvgCenterPoint();
	Point* CalcAvgEndPoint();

	~Cluster();
};

