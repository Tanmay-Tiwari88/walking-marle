#include "Road.h"


Road::Road(Vec City1, Vec City2)
	:
	City1(City1),
	City2(City2)
{
	Line<float> temp=Line<float>(City1, City2);
	float dist = width * std::sin(std::atan(temp.GetSlope()));
	dist /= 2;
	Vec d = Vec(dist, 0);
	l1 = Line<float>(City1 - d, City2 - d);
	l2 = Line<float>(City1 + d, City2 + d);




}

void Road::DrawRoad(Graphics & gfx)
{
	Vec p1 = l1.GetP1();
	Vec p2 = l1.Getp2();
	if (p1.y > p2.y)
		std::swap(p1, p2);
	for (int i = p1.y+1; i < p2.y-1; i++)
	{
		float x1 = (i - l1.GetC()) / l1.GetSlope();
		float x2 = (i - l2.GetC()) / l2.GetSlope();
		Line<float> l = Line<float>(Vec(x1, i), Vec(x2, i));
		gfx.Drawlineseg(l, Colors::Blue);

	}

}

Vec Road::Getcity1()
{
	return City1;
}

Vec Road::Getcity2()
{
	return City2;
}
