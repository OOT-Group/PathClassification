#pragma once
#include "..\Entity\Route.h"
#include "..\stdafx.h"

class ClassfyAlgo {
public:
	virtual std::vector<Route> ClassfyRoute(std::vector<Route> routes) = 0;
};