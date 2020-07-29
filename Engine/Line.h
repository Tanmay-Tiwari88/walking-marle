#pragma once
#include"Vec2.h"
template<typename T>
class Line
{
public:

	Line() = default;


	Line(Vec2<T> p1, Vec2<T> p2)
		:
		p1(p1),
		p2(p2)
	{
		m = (p2.y - p1.y)/(p2.x - p1.x);
		c = p1.y -( m * p1.x);

	}

	T GetSlope() const
	{
		return m;
	}

	T GetC() const
	{
		return c;
	}

	Vec2<T> GetP1() const
	{
		return p1;
	}

	Vec2<T> Getp2() const
	{
		return p2;
	}

private:
	T m;
	T c;
	Vec2<T> p1;
	Vec2<T> p2;
};

