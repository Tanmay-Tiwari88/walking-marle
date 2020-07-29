#pragma once
#include"Animation.h"
class Character
{
private:
	enum class  Sequences
	{
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown,
		Nseq

	};
public:
	Character(float x, float y,int hieght,int width,std::string Filename,int count,float holdTime);
	void update(float dt,Vec in);
	void Draw(Graphics &gfx);
	void setdir(Vec vel);
private:
	Surface s;
	Vec pos;
	Vec	vel=Vec(0.0f,0.0f);
	float speed = 60.0f;
	std::vector<Animation> anime;
	Sequences CurrSeq = Sequences::StandingLeft;
};

