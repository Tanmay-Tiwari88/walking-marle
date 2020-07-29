#include "Animation.h"

Animation::Animation(int x,int y,const Surface & S, int width, int hieght, int nframes, float holdtime)
	:
	surfacce(S),
	holdtime(holdtime),
	nframes(nframes)
{
	for (int i = 0; i < nframes; i++)
		frame.emplace_back(Rect<int>(y, y+ hieght ,x+ i*width,x+(i+1)*width));
}

void Animation::update(float dt)
{
	currTime += dt;
	while (currTime > holdtime)
	{

		currframe++;
		if (currframe >= nframes)
			currframe = 0;
		currTime -= holdtime;
	}

}

void Animation::Draw(Graphics & gfx,int x,int y)
{
	
	gfx.DrawSprite(x,y,surfacce, frame[currframe], Specialeffect::ghost(Colors::Magenta));
}

