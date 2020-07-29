#pragma once
#include"Graphics.h"
#include<cmath>
class Road
{
public:
	Road(Vec City1, Vec City2);
	void DrawRoad(Graphics& gfx);
	Vec Getcity1();
	Vec Getcity2();

private:
	Vec City1;
	Vec City2;
	int width = 50;
	Line<float> l1;
	Line<float> l2;
	

};

