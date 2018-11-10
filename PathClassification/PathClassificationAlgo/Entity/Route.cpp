#include "..\stdafx.h"
#include "Route.h"

Route::Route()
{
}


void Route::GenerateCenterPoint()
{
	int length = points.size();										  // ��ȡ�㼯����
	double xAvg = 0, yAvg = 0;
	for (int i = 1; i < length - 1; i++)							  // ����ÿ������
	{
		Point pA = points[i-1];                                         // ͷһ����
		Point pB = points[i];                                     // ��һ����
		double x = (pB.GetX() + pA.GetX()) / 2;                       // ƽ��xֵ
		double y = (pB.GetY() + pA.GetY()) / 2;                       // ƽ��yֵ
		xAvg += this->distances[i-1] * x;                           // X��Ȩ
		yAvg += this->distances[i-1] * y;                           // Y��Ȩ
	}
	xAvg = xAvg / this->totalDistance;                                // ��Ȩƽ��x
	yAvg = yAvg / this->totalDistance;                                // ��Ȩƽ��y
	Point pointAvg(xAvg,yAvg);									  // �½���
	centerPoint = pointAvg;											  // ��������
}

void Route::GenerateRouteDistances()
{
	int length = points.size();										  // ��ȡ�㼯����
	double totalLength = 0;
	for (int i = 1; i < length - 1; i++)
	{
		Point pA = points[i-1];                                       // ͷһ����
		Point pB = points[i];                                   // ��һ����
		double dis = pA.CalcDistance(pB);							  // ��ȡ����
		distances.push_back(dis);									  // ��ӵ������б�ȥ
		totalLength += dis;											  // �����ܳ���
	}
	totalDistance = totalLength;
}

Route::~Route()
{
}
