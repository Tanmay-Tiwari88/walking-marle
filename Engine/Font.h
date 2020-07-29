#pragma once
#include<string>
#include "Surface.h"
#include"Graphics.h"
#include"Rect.h"
#include"Specialeffect.h"
class Font
{

public:
	Font(std::string Filename);
	void printString(std::string str, Graphics& gfx,Vec pos);

private:
	Rect<int> GetGlyphRect( int x,int y);

	
private:
	char Startglyph=' ';
	char endglyph= '~';
	Surface S;
	int Hieght;
	int Width;
	int nCols=32;
	int nRows=3;
	int GlyphHieght;
	int GlyphWidth;

};

