#include "../stdafx.h"
#include "Judge.h"


Judge::Judge()
{
}

std::vector<Route> Judge::ClassfyRoute(std::vector<Route>& routes)
{
	for (int i = 0; i < routes.size(); i++)		// 对每条路径计算线长和形心
	{
		// TODU : 路径初始化点集生成
		routes[i].GenerateRouteDistances();
		routes[i].GenerateCenterPoint();
	}
	// Kmeans++
	// 第一次分类
	Init(routes);
	for (int i = 0; i < 1; i++)				// 这里的10，可以定义为宏，也可以输入，为使Kmeans聚类更加精确
	{
		avgCluster();							// 计算聚类平均点，然后清空聚类中的路径
		for (int j = 0; j < routes.size(); j++)	// 对每一条路径重新判断是否与已经存在的某个聚类更近，再重新添加入聚类中
		{
			checkCluster(routes[j]);
		}
	}
	return routes;
}

bool Judge::Similar(Point& p1, Point& p2)
{
	double check = p1.CalcDistance(p2);		// 检测点距
	if(check <= distancePara)					// 满足条件
		return true;
	return false;
}

bool Judge::Similar(Route& route1, Route& route2)
{
	double bendRate1 = (route1.GetTotalDistance() / (route1.GetPoints().at(0).CalcDistance(route1.GetPoints().back() ) ) );		// 第一条路径曲度
	double bendRate2 = (route2.GetTotalDistance() / (route2.GetPoints().at(0).CalcDistance(route2.GetPoints().back() ) ) );		// 第二条路径曲度
	if (abs(bendRate1 - bendRate2) <= bendPara)		// 曲度是否在曲度参数范围内
		return true;
	return false;
}

bool Judge::CheckSimilar(Route& route1, Route& route2)
{
	if (Similar(route1, route2))		// 判断两条路径曲度是否在参数范围内
		if (Similar(route1.GetPoints().at(0), route2.GetPoints().at(0)))		// 判断两条路径的起始点距是否在参数范围内
			if (Similar(route1.GetPoints().back(), route2.GetPoints().back()))		// 判断两条路径的终止点距是否在参数范围内
				if (Similar(route1.GetCenterPoint(), route2.GetCenterPoint()))					// 判断两条路径的形心点距是否在参数范围内
					return true;
	return false;
}


void Judge::Init(std::vector<Route>& routes)
{
	Clusters.push_back(Cluster());					// 新建聚类，加入聚类列表
	Clusters[0].GetRoutes().push_back(routes[0]);		// 将第0条路径加入该聚类
	for (int i = 1; i < routes.size(); i++)				// 遍历后面的路径，判断与聚类列表已存在的聚类第一条路径是否相似
	{
		bool setFlag = FALSE;							// 判断路径是否加入聚类
		for (int j = 0; j < Clusters.size(); j++)
		{
			if (CheckSimilar(routes[i], Clusters[j].GetRoutes().at(0)))	// 若相似，将其加入与其相似的聚类
			{
				Clusters[j].GetRoutes().push_back(routes[i]);
				setFlag = TRUE;
				break;
			}
		}
		if (!setFlag)									// 若不相似，新建聚类包含这条路径，再把聚类放到聚类列表
		{
			Cluster clus;
			clus.GetRoutes().push_back(routes[i]);
			Clusters.push_back(clus);
		}
	}
}

void Judge::avgCluster()
{
	int nums = Clusters.size();                 // 获取当前聚类数量
	for (int i = 0; i < nums;)                 
	{
		Cluster* clus = &Clusters[i];              
		if (clus->GetRoutes().size() == 0)      // 若某个聚类中没有路径，清掉这个聚类
			Clusters.erase(Clusters.begin()+i);          
		else									// 如果这个聚类中有路径的话，计算聚类平均点，再清掉这个聚类中的路径
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
	double min = DBL_MAX;							// 取一个最小值
	int index = 0;                                  // 获取聚类的编号
	for (int i = 0; i < Clusters.size(); i++)       // 遍历所有聚类
	{
		double dis = Clusters[i].CalcRouteToClusterDistance(route);      // 计算路径到聚类的距离是否小于其最小值
		if (dis < min)                              // 如果小于最小值就更新聚类的编号并更新最小值
		{
			index = i;                              
			min = dis;                              
		}
	}
	Clusters[index].GetRoutes().push_back(route);	// 将这条路径放入距离最小的编号的聚类中
	route.SetFlag(index);							// 设置其flag为其聚类列表的索引值
}

Judge::~Judge()
{
}
