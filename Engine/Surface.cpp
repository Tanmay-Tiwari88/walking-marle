#include "Surface.h"

Surface::Surface(std::string filename)
{
	std::ifstream file(filename, std::ios::binary);
	BITMAPFILEHEADER	bitMapFileHeader;
	file.read(reinterpret_cast<char*>(&bitMapFileHeader), sizeof(bitMapFileHeader));
	BITMAPINFOHEADER bmInfoHeader;
	file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));
	assert(bmInfoHeader.biBitCount == 24 || bmInfoHeader.biBitCount == 32);
	assert(bmInfoHeader.biCompression == 0);
	 Hieght = bmInfoHeader.biHeight;
	 Width = bmInfoHeader.biWidth;
	 int padding = (4 -(Width % 4)) % 4;

	bool is32 = bmInfoHeader.biBitCount == 32;

	int ystart, yend, dy;

	file.seekg(bitMapFileHeader.bfOffBits);
	if (bmInfoHeader.biHeight < 0)
	{
		Hieght = -1 *Hieght;
		ystart = 0;
		yend = Hieght ;
		dy = 1;
	}
	else
	{
		ystart = Hieght-1;
		yend = -1;
		dy = -1;

	}
	Bitmap = new Color[Hieght*Width];
	for (int y = ystart; y != yend; y += dy)
	{
		for (int x = 0; x < Width; x++)
		{
			int b = file.get();
			int g = file.get();
			int r = file.get();
			putpixel(x, y, Color( r,g,b ));
			if (is32)
			{
				file.seekg(1, std::ios::cur);
			}
		}
		if (!is32)
		{
			file.seekg(padding, std::ios::cur);
		}

	}

}

Surface::Surface(const Surface & rhs)
{
	Hieght = rhs.GetHieght();
	Width = rhs.GetWidth();

	Bitmap = new Color[Hieght*Width];

	for (int i = 0; i < Hieght; i++)
	{
		for (int j = 0; j < Width; j++)
			putpixel(i, j, rhs.Getpixel(i, j));
	}
}

Surface Surface::operator=(const Surface & rhs)
{

	delete[]Bitmap;
	Hieght = rhs.GetHieght();
	Width = rhs.GetWidth();

	Bitmap = new Color[Hieght*Width];

	for (int i = 0; i < Hieght; i++)
	{
		for (int j = 0; j < Width; j++)
			putpixel(i, j, rhs.Getpixel(i, j));
	}
	return *this;
	
}

Surface::~Surface()
{
	delete[]Bitmap;
	Bitmap = nullptr;
}




int Surface::GetHieght() const
{
	return Hieght;
}

int Surface::GetWidth() const
{
	return Width;
}

Color Surface::Getpixel(int x, int y) const
{
	return Bitmap[y*Width + x];
}

void Surface::putpixel(int x, int y, Color c)
{
	Bitmap[y*Width + x] = c;
}
