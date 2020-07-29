#pragma once


namespace Specialeffect
{
	class chroma
	{
	public:
		chroma(Color chrom)
			:
			chrom(chrom)
		{

		}

		void operator()(int x, int y, Color pix, Graphics& gfx)
		{
			if (pix != chrom)
				gfx.PutPixel(x, y, pix);
		}
	private:
		Color chrom;
	};
	class ghost
	{
	public:
		ghost(Color chrom)
			:
			chrom(chrom)
		{
			
		}
		void operator ()(int x, int y, Color pix, Graphics& gfx)
		{
			if ( pix!= chrom)
			{
				Color dstpix = gfx.Getpixel(x, y);
				Color newpix = { unsigned char(pix.GetR() / 2 + dstpix.GetR() / 2),
					unsigned char(pix.GetG() / 2 + dstpix.GetG() / 2),
					unsigned char(pix.GetB() / 2 + dstpix.GetB() / 2) };
					gfx.PutPixel(x, y, newpix);
			}
		}
	private:
		Color chrom;
	};
	class Sub
	{
	public:
		Sub(Color chrom,Color sub)
			:
			chrom(chrom),
			sub(sub)
		{

		}
		void operator ()(int x, int y, Color pix, Graphics& gfx)
		{
			if (pix != chrom)
			{
				
				gfx.PutPixel(x, y, sub);
			}
		}
	private:
		Color chrom;
		Color sub;
	};
}
