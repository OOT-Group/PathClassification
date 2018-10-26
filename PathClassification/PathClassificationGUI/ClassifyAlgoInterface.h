#pragma once
#include<vector>
class  ClassifyAlgoInterface
{
public:
	ClassifyAlgoInterface();
	virtual std::vector<ClassifiedRoute> ClassfyPath(std::vector<Route> routes)=0;
	~ClassifyAlgoInterface();
};


class Point {

};

class Route {
public:
	std::vector<Point> points;

};

class ClassifiedRoute {

};

