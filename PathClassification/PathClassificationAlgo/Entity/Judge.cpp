#include "../stdafx.h"
#include "Judge.h"


Judge::Judge()
{
}

std::vector<Route>* Judge::ClassfyRoute(const std::vector<Route>& routes)
{

	return nullptr;
}

bool Judge::Similar(const Point * p1, const Point * p2)
{
	double check = p1->CalcDistance(p2);		// �����
	if(check <= distancePara)					// ��������
		return true;
	return false;
}

bool Judge::Similar(const Route * route1, const Route * route2)
{
	std::vector<Point>* points = route1->GetPoints();		
	std::vector<Point>* _points = route2->GetPoints();
	double bendRate1 = (route1->GetTotalDistance / (points->at(0).CalcDistance(points->back() ) ) );		// ��һ��·������
	double bendRate2 = (route2->GetTotalDistance / (_points->at(0).CalcDistance(_points->back() ) ) );		// �ڶ���·������
	if (abs(bendRate1 - bendRate2) <= bendPara)		// �����Ƿ������Ȳ�����Χ��
		return true;
	return false;
}

bool Judge::CheckSimilar(const Route * route1, const Route * route2)
{
	std::vector<Point>* points = route1->GetPoints();
	std::vector<Point>* _points = route2->GetPoints();
	if (Similar(route1, route2))		// �ж�����·�������Ƿ��ڲ�����Χ��
		if (Similar(points->at(0), _points->at(0)))		// �ж�����·������ʼ����Ƿ��ڲ�����Χ��
			if (Similar(points->back(), _points->back()))		// �ж�����·������ֹ����Ƿ��ڲ�����Χ��
				if (Similar(route1->GetCenterPoint(), route2->GetCenterPoint()))		// �ж�����·�������ĵ���Ƿ��ڲ�����Χ��
					return true;
	return false;
}


Judge::~Judge()
{
}
