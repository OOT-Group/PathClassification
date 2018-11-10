#include "../stdafx.h"
#include "Cluster.h"


Cluster::Cluster()
{
}


double Cluster::CalcRouteToClusterDistance(Route & route)
{
	std::vector<Point> points = route.GetPoints();
	return (points.at(0)).CalcDistance(avgStartPoint)                 // ��ʼ�㵽ƽ����ʼ��
		+ (points.back()).CalcDistance(avgEndPoint)					 // �յ㵽ƽ���յ�
		+ route.GetCenterPoint().CalcDistance(avgCenterPoint);          // ���ĵ�ƽ������
}

Point  Cluster::CalcAvgStartPoint()
{
	int n = routes.size();									    // ��ȡ·����
	double startX = 0, startY = 0;								// ��ʼ����ʱ����
	for (int i = 0; i < n; i++)								    // ��������·��
	{
		std::vector<Point> points = routes[i].GetPoints();	    // ��ȡ·�ߵ㼯
		startX += points.at(0).GetX();                         // ȡ��ʼ��
		startY += points.at(0).GetY();                         // ȡ��ʼ��
	}
	avgStartPoint.SetX((double)startX / n + 0.5f);				// ����ƽ����ʼ��
	avgStartPoint.SetY((double)startY / n + 0.5f);				// ����ƽ����ʼ��
	
	return avgStartPoint;
}

Point Cluster::CalcAvgCenterPoint()
{
	int n = routes.size();										// ��ȡ·����
	double centerX = 0, centerY = 0;							// ��ʼ����ʱ����
	for (int i = 0; i < n; i++)									// ��������·��
	{
		Point points = routes[i].GetCenterPoint();				// ��ȡ·�����ĵ㼯
		centerX += points.GetX();								// ȡ���ĵ�
		centerY += points.GetY();								// ȡ���ĵ�
	}
	avgCenterPoint.SetX((double)centerX / n + 0.5f);			// ����ƽ�����ĵ�
	avgCenterPoint.SetY((double)centerY / n + 0.5f);			// ����ƽ�����ĵ�
	return avgCenterPoint;
}

Point Cluster::CalcAvgEndPoint()
{
	int n = routes.size();										// ��ȡ·����
	double endX = 0, endY = 0;									// ��ʼ����ʱ����
	for (int i = 0; i < n; i++)									// ��������·��
	{
		std::vector<Point> points = routes[i].GetPoints();		// ��ȡ·�ߵ㼯
		endX += points.back().GetX();							// ȡ��ֹ��
		endY += points.back().GetY();							// ȡ��ֹ��
	}
	avgEndPoint.SetX((double)endX / n + 0.5f);					// ����ƽ����ֹ��
	avgEndPoint.SetY((double)endY / n + 0.5f);					// ����ƽ����ֹ��
	return avgEndPoint;
}

Cluster::~Cluster()
{
}
