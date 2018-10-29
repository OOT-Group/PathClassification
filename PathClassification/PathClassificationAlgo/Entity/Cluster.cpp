#include "../stdafx.h"
#include "Cluster.h"


Cluster::Cluster()
{
}


Point * Cluster::CalcAvgStartPoint()
{
	int n = routes.size();					    //获取路径数
												// n为0
	//int startX = 0, startY = 0;					//初始化临时变量
	//for (int i = 0; i < n; i++)                             //遍历所有路线
	//{
	//	Point points = routes[i].points;					//获取路线点集
	//	startX += points[0].x;                              //取起始点
	//	startY += points[0].y;                              //取起始点
	//}
	//avgStartPoint->SetX((int)((float)startX / n + 0.5f));      //计算平均起始点
	//avgStartPoint->SetY((int)((float)startY / n + 0.5f));      //计算平均起始点
	return avgStartPoint;
}

Cluster::~Cluster()
{
}
