#include "../stdafx.h"
#include "Judge.h"


Judge::Judge()
{
}

std::vector<Route> Judge::ClassfyRoute(std::vector<Route>& routes)
{
	for (int i = 0; i < routes.size(); i++)		// ��ÿ��·�������߳�������
	{
		// TODU : ·����ʼ���㼯����
		routes[i].GenerateRouteDistances();
		routes[i].GenerateCenterPoint();
	}
	// Kmeans++
	// ��һ�η���
	Init(routes);
	for (int i = 0; i < 1; i++)				// �����10�����Զ���Ϊ�꣬Ҳ�������룬ΪʹKmeans������Ӿ�ȷ
	{
		avgCluster();							// �������ƽ���㣬Ȼ����վ����е�·��
		for (int j = 0; j < routes.size(); j++)	// ��ÿһ��·�������ж��Ƿ����Ѿ����ڵ�ĳ���������������������������
		{
			checkCluster(routes[j]);
		}
	}
	return routes;
}

bool Judge::Similar(Point& p1, Point& p2)
{
	double check = p1.CalcDistance(p2);		// �����
	if(check <= distancePara)					// ��������
		return true;
	return false;
}

bool Judge::Similar(Route& route1, Route& route2)
{
	double bendRate1 = (route1.GetTotalDistance() / (route1.GetPoints().at(0).CalcDistance(route1.GetPoints().back() ) ) );		// ��һ��·������
	double bendRate2 = (route2.GetTotalDistance() / (route2.GetPoints().at(0).CalcDistance(route2.GetPoints().back() ) ) );		// �ڶ���·������
	if (abs(bendRate1 - bendRate2) <= bendPara)		// �����Ƿ������Ȳ�����Χ��
		return true;
	return false;
}

bool Judge::CheckSimilar(Route& route1, Route& route2)
{
	if (Similar(route1, route2))		// �ж�����·�������Ƿ��ڲ�����Χ��
		if (Similar(route1.GetPoints().at(0), route2.GetPoints().at(0)))		// �ж�����·������ʼ����Ƿ��ڲ�����Χ��
			if (Similar(route1.GetPoints().back(), route2.GetPoints().back()))		// �ж�����·������ֹ����Ƿ��ڲ�����Χ��
				if (Similar(route1.GetCenterPoint(), route2.GetCenterPoint()))					// �ж�����·�������ĵ���Ƿ��ڲ�����Χ��
					return true;
	return false;
}


void Judge::Init(std::vector<Route>& routes)
{
	Clusters.push_back(Cluster());					// �½����࣬��������б�
	Clusters[0].GetRoutes().push_back(routes[0]);		// ����0��·������þ���
	for (int i = 1; i < routes.size(); i++)				// ���������·�����ж�������б��Ѵ��ڵľ����һ��·���Ƿ�����
	{
		bool setFlag = FALSE;							// �ж�·���Ƿ�������
		for (int j = 0; j < Clusters.size(); j++)
		{
			if (CheckSimilar(routes[i], Clusters[j].GetRoutes().at(0)))	// �����ƣ���������������Ƶľ���
			{
				Clusters[j].GetRoutes().push_back(routes[i]);
				setFlag = TRUE;
				break;
			}
		}
		if (!setFlag)									// �������ƣ��½������������·�����ٰѾ���ŵ������б�
		{
			Cluster clus;
			clus.GetRoutes().push_back(routes[i]);
			Clusters.push_back(clus);
		}
	}
}

void Judge::avgCluster()
{
	int nums = Clusters.size();                 // ��ȡ��ǰ��������
	for (int i = 0; i < nums;)                 
	{
		Cluster* clus = &Clusters[i];              
		if (clus->GetRoutes().size() == 0)      // ��ĳ��������û��·��������������
			Clusters.erase(Clusters.begin()+i);          
		else									// ��������������·���Ļ����������ƽ���㣬�������������е�·��
		{
			clus->CalcAvgStartPoint();
			clus->CalcAvgEndPoint();
			clus->CalcAvgCenterPoint();
			clus->GetRoutes().clear();
			i++;
		}
	}
}

void Judge::checkCluster(Route& route)
{
	double min = DBL_MAX;							// ȡһ����Сֵ
	int index = 0;                                  // ��ȡ����ı��
	for (int i = 0; i < Clusters.size(); i++)       // �������о���
	{
		double dis = Clusters[i].CalcRouteToClusterDistance(route);      // ����·��������ľ����Ƿ�С������Сֵ
		if (dis < min)                              // ���С����Сֵ�͸��¾���ı�Ų�������Сֵ
		{
			index = i;                              
			min = dis;                              
		}
	}
	Clusters[index].GetRoutes().push_back(route);	// ������·�����������С�ı�ŵľ�����
	route.SetFlag(index);							// ������flagΪ������б������ֵ
}

Judge::~Judge()
{
}
