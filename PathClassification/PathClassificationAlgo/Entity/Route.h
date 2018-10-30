#pragma once
#include "Point.h"
#include <vector>
class Route
{
private:
	std::vector<Point> points;
	int flag;
	std::vector<double> distances;
	double totalDistance;
	Point* centerPoint;
	double bendRate;
	int num;
public:
	Route();
	void SetPoints(std::vector<Point>& points) { this->points = points; }
	std::vector<Point>* GetPoints() { return &points; }

	void SetFlag(int flag) { this->flag = flag; }
	int GetFlag() { return flag; }

	void SetDistances(std::vector<double>& distances) { this->distances = distances; }
	std::vector<double>* GetDistances() { return &distances; }

	void SetTotalDistance(int distance) { this->totalDistance = distance; }
	int GetTotalDistance() { return totalDistance; }

	void SetCenterPoint(Point* point) { this->centerPoint = point; }
	Point* GetCenterPoint() { return centerPoint; }

	void SetBendRate(double distance) { this->bendRate = bendRate; }
	int GetBendRate() { return bendRate; }

	void SetNum(int num) { this->num = num; }
	int GetNum() { return num; }

	void GenerateCenterPoint();			// 生成形心
	void GenerateRouteDistances();		// 生成路径长度

	~Route();
};

