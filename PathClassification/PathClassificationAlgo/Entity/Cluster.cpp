#include "../stdafx.h"
#include "Cluster.h"


Cluster::Cluster()
{
}


double Cluster::CalcRouteToClusterDistance(Route & route)
{
	std::vector<Point> points = route.GetPoints();
	return (points.at(0)).CalcDistance(avgStartPoint)                 // 起始点到平均起始点
		+ (points.back()).CalcDistance(avgEndPoint)					 // 终点到平均终点
		+ route.GetCenterPoint().CalcDistance(avgCenterPoint);          // 形心到平均形心
}

Point  Cluster::CalcAvgStartPoint()
{
	int n = routes.size();									    // 获取路径数
	double startX = 0, startY = 0;								// 初始化临时变量
	for (int i = 0; i < n; i++)								    // 遍历所有路线
	{
		std::vector<Point> points = routes[i].GetPoints();	    // 获取路线点集
		startX += points.at(0).GetX();                         // 取起始点
		startY += points.at(0).GetY();                         // 取起始点
	}
	avgStartPoint.SetX((double)startX / n + 0.5f);				// 计算平均起始点
	avgStartPoint.SetY((double)startY / n + 0.5f);				// 计算平均起始点
	
	return avgStartPoint;
}

Point Cluster::CalcAvgCenterPoint()
{
	int n = routes.size();										// 获取路径数
	double centerX = 0, centerY = 0;							// 初始化临时变量
	for (int i = 0; i < n; i++)									// 遍历所有路线
	{
		Point points = routes[i].GetCenterPoint();				// 获取路线形心点集
		centerX += points.GetX();								// 取形心点
		centerY += points.GetY();								// 取形心点
	}
	avgCenterPoint.SetX((double)centerX / n + 0.5f);			// 计算平均形心点
	avgCenterPoint.SetY((double)centerY / n + 0.5f);			// 计算平均形心点
	return avgCenterPoint;
}

Point Cluster::CalcAvgEndPoint()
{
	int n = routes.size();										// 获取路径数
	double endX = 0, endY = 0;									// 初始化临时变量
	for (int i = 0; i < n; i++)									// 遍历所有路线
	{
		std::vector<Point> points = routes[i].GetPoints();		// 获取路线点集
		endX += points.back().GetX();							// 取终止点
		endY += points.back().GetY();							// 取终止点
	}
	avgEndPoint.SetX((double)endX / n + 0.5f);					// 计算平均终止点
	avgEndPoint.SetY((double)endY / n + 0.5f);					// 计算平均终止点
	return avgEndPoint;
}

Cluster::~Cluster()
{
}
