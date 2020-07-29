#pragma once
#include "Vec2.h"

template<typename T>

class Rect
{
public:

	Rect(T top,T bottom,T left,T right)
		:
		top(top),
		bottom(bottom),
		left(left),
		right(right)
	{

	}
	Rect(Vec2<T> topleft, Vec2<T> bottomright)
		:
		Rect(topleft.y, bottomright.y, topleft.x, bottomright.x)
	{
	 
	}
	Rect(Vec2<T> topleft, T hieght, T width)
		:
		Rect(topleft, topleft + Vec2<T>(width, hieght))
	{
		 
	}
	bool isOverlapping(const Rect& r)
	{
		return r.right > left && r.left < right
			&& r.top < bottom && r.bottom > top;
	}
	
	bool isContainedby(const Rect& r)
	{
		return right <= r.right && left >= r.left
			&& bottom <= r.bottom && top >= r.top;
	}

	Rect GetRectCent(const Vec2<T>& cen, T halwidth, T halfhieght)
	{
		Vec2<T> scale(halwidth, halfhieght);
		return Rect(cen - scale, cen + scale);

	}
	Vec2<T> Getcen()
	{
		return Vec2<T>((right + left) / 2, (top + bottom) / 2);
	}
	Rect Expnad(T offset)
	{
		return Rect(left - offset, right + offset, top - offset, bottom + offset);
	}
	
	T GetWidth()
	{
		return right - left;
	}
	T GetHieght()
	{
		return bottom - top;
	}
	


public:
	T top;
	T bottom;
	T left;
	T right;

};

