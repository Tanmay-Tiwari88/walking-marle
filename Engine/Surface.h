#pragma once
#include"Colors.h"
#include"ChiliWin.h"
#include<string>
#include<fstream>
#include<cassert>
class Surface
{
public:
	Surface(std::string filename);
	Surface(const Surface& rhs);
	Surface operator =(const Surface& rhs);
	~Surface();
	int GetHieght() const;
	int GetWidth() const;
	Color Getpixel(int x, int y) const;
private:
	void putpixel(int x, int y,Color c);

private:
	int Hieght;
	int Width;
	Color *Bitmap;
};

