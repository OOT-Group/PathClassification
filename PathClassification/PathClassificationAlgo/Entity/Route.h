#pragma once
#include "Point.h"
#include <vector>
class Route
{
private:
	std::vector<Point> points;
	int flag;
	std::vector<double> distances;
	double distance;
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

	void SetDistance(int distance) { this->distance = distance; }
	int GetDistance() { return distance; }

	void SetCenterPoint(Point* point) { this->centerPoint = point; }
	Point* GetCenterPoint() { return centerPoint; }

	void SetBendRate(double distance) { this->bendRate = bendRate; }
	int GetBendRate() { return bendRate; }

	void SetNum(int num) { this->num = num; }
	int GetNum() { return num; }

	~Route();
};

