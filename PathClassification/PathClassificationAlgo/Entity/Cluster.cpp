#include "../stdafx.h"
#include "Cluster.h"


Cluster::Cluster()
{
}


Point * Cluster::CalcAvgStartPoint()
{
	int n = routes.size();					    //��ȡ·����
												// nΪ0
	//int startX = 0, startY = 0;					//��ʼ����ʱ����
	//for (int i = 0; i < n; i++)                             //��������·��
	//{
	//	Point points = routes[i].points;					//��ȡ·�ߵ㼯
	//	startX += points[0].x;                              //ȡ��ʼ��
	//	startY += points[0].y;                              //ȡ��ʼ��
	//}
	//avgStartPoint->SetX((int)((float)startX / n + 0.5f));      //����ƽ����ʼ��
	//avgStartPoint->SetY((int)((float)startY / n + 0.5f));      //����ƽ����ʼ��
	return avgStartPoint;
}

Cluster::~Cluster()
{
}
