#include "../stdafx.h"
#include "Judge.h"


Judge::Judge()
{
}

std::vector<Route>* Judge::ClassfyRoute(std::vector<Route>& routes)
{
	// ...
	return nullptr;
}

bool Judge::Similar(Point * p1, Point * p2)
{
	double check = p1->CalcDistance(p2);		// �����
	if(check <= distancePara)					// ��������
		return true;
	return false;
}

bool Judge::Similar(Route * route1, Route * route2)
{
	double bendRate1 = (route1->GetTotalDistance() / (route1->GetPoints()->at(0).CalcDistance(&route1->GetPoints()->back() ) ) );		// ��һ��·������
	double bendRate2 = (route2->GetTotalDistance() / (route2->GetPoints()->at(0).CalcDistance(&route2->GetPoints()->back() ) ) );		// �ڶ���·������
	if (abs(bendRate1 - bendRate2) <= bendPara)		// �����Ƿ������Ȳ�����Χ��
		return true;
	return false;
}

bool Judge::CheckSimilar(Route * route1, Route * route2)
{
	if (Similar(route1, route2))		// �ж�����·�������Ƿ��ڲ�����Χ��
		if (Similar(&route1->GetPoints()->at(0), &route2->GetPoints()->at(0)))		// �ж�����·������ʼ����Ƿ��ڲ�����Χ��
			if (Similar(&route1->GetPoints()->back(), &route2->GetPoints()->back()))		// �ж�����·������ֹ����Ƿ��ڲ�����Χ��
				if (Similar(route1->GetCenterPoint(), route2->GetCenterPoint()))					// �ж�����·�������ĵ���Ƿ��ڲ�����Χ��
					return true;
	return false;
}


Judge::~Judge()
{
}
