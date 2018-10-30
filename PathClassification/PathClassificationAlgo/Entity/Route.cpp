#include "..\stdafx.h"
#include "Route.h"


Route::Route()
{
}


void Route::GenerateCenterPoint()
{
	int length = points.size();										  // 获取点集长度
	double xAvg = 0, yAvg = 0;
	for (int i = 0; i < length - 1; i++)							  // 遍历每两个点
	{
		Point pA = points[i];                                         // 头一个点
		Point pB = points[i + 1];                                     // 后一个点
		double x = (pB.GetX() + pA.GetX()) / 2;                       // 平均x值
		double y = (pB.GetY() + pA.GetY()) / 2;                       // 平均y值
		xAvg += this->distances[i + 1] * x;                           // X加权
		yAvg += this->distances[i + 1] * y;                           // Y加权
	}
	xAvg = xAvg / this->totalDistance;                                // 加权平均x
	yAvg = yAvg / this->totalDistance;                                // 加权平均y
	Point* pointAvg = new Point;									  // 新建点
	pointAvg->SetX(xAvg); 
	pointAvg->SetY(yAvg);
	centerPoint = pointAvg;											  // 生成形心
}

void Route::GenerateRouteDistances()
{
	int length = points.size();										  // 获取点集长度
	double totalLength = 0;
	for (int i = 0; i < length - 1; i++)
	{
		Point* pA = &points[i];                                       // 头一个点
		Point* pB = &points[i + 1];                                   // 后一个点
		double dis = pA->CalcDistance(pB);							  // 获取距离
		distances.push_back(dis);									  // 添加到长度列表去
		totalLength += dis;											  // 计算总长度
	}
	totalDistance = totalLength;
}

Route::~Route()
{
}
