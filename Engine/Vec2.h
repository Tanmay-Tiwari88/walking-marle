#pragma once
#include<cmath>


template<typename T>
class Vec2
{

//member function
public:
	Vec2() = default;
	Vec2(T x, T y)
		:
		x(x),
		y(y)
	{
	}

	Vec2 Vec2<T>::operator+(const Vec2 & rhs) const
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}
	
	Vec2& operator +=(const Vec2 & rhs)
	{
		return *this = rhs + *this;
	}

	Vec2 operator -(const Vec2 & rhs)
	{
		return Vec2(x - rhs.x, y - rhs.y);
	}

	Vec2& operator  -=(const Vec2 & rhs)
	{
		return *this= *this - rhs;
	}

	Vec2 operator *(T s) const
	{
		return Vec2(s*x, s*y);
	}

	Vec2& operator *=(int s)
	{
		return *this =  *this * s;
	}
	T GetLen()
	{
		return T(sqrt(pow(x, 2) + pow(y, 2)));
	}
	T GetLensq()
	{
		return T( pow(x, 2) + pow(y, 2) );
	}

	Vec2 GetNormalized()
	{
		T len = GetLen();
		if (len != 0.0f)
		{
			return Vec2(x / len, y / len);
		}
		return *this;
	}
	template<typename P>
	Vec2 GetVec(Vec2<P> out)
	{
		return Vec2(T(x), T(y));
	}

//member variables
public:
	T x;
	T y;
};
typedef Vec2<int> Vei;
typedef Vec2<float> Vec;