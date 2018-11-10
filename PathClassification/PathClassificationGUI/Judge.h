#pragma once
#include "IClassfyAlgo.h"
#include "Cluster.h"
class  Judge :
	public IClassfyAlgo
{
public:
	Judge();
	std::vector<Cluster> Clusters;		// 聚类列表

	std::vector<Route> ClassfyRoute(std::vector<Route>& routes);	// TODU
	~Judge();
private:
	bool Similar(Point &p1, Point &p2);				// 判断两点间距离是否在参数范围内
	bool Similar(Route &route1, Route &route2);		// 判断两路径曲度是否在参数范围内
	bool CheckSimilar(Route& route1, Route& route2);// 判断两路径是否相似

	void Init(std::vector<Route>& routes);			// 第一次聚类
	void avgCluster();								// 计算聚类平均点
	void checkCluster(Route& route);							// 检查聚类
};

