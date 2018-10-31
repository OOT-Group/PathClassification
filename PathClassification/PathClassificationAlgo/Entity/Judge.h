#pragma once
#include "../interface/IClassfyAlgo.h"
class Judge :
	public IClassfyAlgo
{
public:
	Judge();
	std::vector<Route>* ClassfyRoute(std::vector<Route>& routes);
	bool Similar(Point* p1, Point* p2);				// �ж����������Ƿ��ڲ�����Χ��
	bool Similar(Route* route1, Route* route2);		// �ж���·�������Ƿ��ڲ�����Χ��
	bool CheckSimilar(Route* route1, Route* route2);// �ж���·���Ƿ�����
	~Judge();
};

