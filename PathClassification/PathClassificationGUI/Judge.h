#pragma once
#include "IClassfyAlgo.h"
#include "Cluster.h"
class  Judge :
	public IClassfyAlgo
{
public:
	Judge();
	std::vector<Cluster> Clusters;		// �����б�

	std::vector<Route> ClassfyRoute(std::vector<Route>& routes);	// TODU
	~Judge();
private:
	bool Similar(Point &p1, Point &p2);				// �ж����������Ƿ��ڲ�����Χ��
	bool Similar(Route &route1, Route &route2);		// �ж���·�������Ƿ��ڲ�����Χ��
	bool CheckSimilar(Route& route1, Route& route2);// �ж���·���Ƿ�����

	void Init(std::vector<Route>& routes);			// ��һ�ξ���
	void avgCluster();								// �������ƽ����
	void checkCluster(Route& route);							// ������
};

