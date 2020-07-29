#pragma once
#include"Graphics.h"
#include<string>
#include<vector>
#include"Specialeffect.h"
class Animation
{

public:
	Animation(int x, int y, const Surface& S, int width, int hieght, int nframes, float holdtime );
	void update(float dt);
	void Draw(Graphics& gfx,int x,int y);
private:
	const Surface& surfacce;
	std::vector<Rect<int>>frame;
	float holdtime;
	float currTime = 0;
	int nframes;
	int currframe = 0;
};

