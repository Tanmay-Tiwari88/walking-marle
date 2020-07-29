#include "Font.h"

Font::Font(std::string Filename)
	:
	S(Filename),
	Hieght(S.GetHieght()),
	Width(S.GetWidth())
{
	GlyphHieght = Hieght / nRows;
	GlyphWidth = Width / nCols;
}

void Font::printString(std::string str, Graphics & gfx,Vec pos)
{
	Vec ppos = pos;
	for (char c:str)
	{
		if (c == '\n')
		{
			ppos.x = pos.x;
			ppos.y += float( GlyphHieght);
		}
		if (c > ' ' &&  c <= '~')
		{
			int in = c - Startglyph;
			int xin = in / nCols;
			int yin = (in % nCols);
			gfx.DrawSprite(int(ppos.x), int(ppos.y), S, GetGlyphRect(xin, yin), Specialeffect::Sub(Colors::White, Colors::White));
			ppos.x +=float( GlyphWidth);
		}
	}
	
}

Rect<int> Font::GetGlyphRect(int x ,int y)
{

	return	{x*GlyphHieght,x*GlyphHieght+GlyphHieght,y*GlyphWidth,y*GlyphWidth+GlyphWidth};

}
