#include "Character.h"



Character::Character(float x,float y,int hieght, int width, std::string Filename, int count,float holdTime)
	:
	pos(Vec(x,y)),
	s(Filename)
{
	for (int i = int(Sequences::WalkingLeft); i < int(Sequences::StandingLeft); i++)
	{
		anime.emplace_back(Animation(width, i*width, s, hieght, width, count, holdTime));
	}
	for (int i = int(Sequences::StandingLeft); i <int(Sequences::Nseq) ; i++)
	{
		anime.emplace_back(Animation(0,(i - int(Sequences::StandingLeft))*hieght,s,hieght,width,1,holdTime));
	}
}

void Character::update(float dt,Vec in)
{
	vel = in;
	setdir(vel);
	pos +=(vel * speed)*dt;
	anime[int(CurrSeq)].update(dt);

}

void Character::Draw(Graphics & gfx)
{
	anime[int(CurrSeq)].Draw(gfx,int(pos.x),int(pos.y));
}

void Character::setdir(Vec vel)
{
	if (vel.x > 0)
	{
		CurrSeq = Sequences::WalkingRight;
	}
	else if (vel.x < 0)
	{
		CurrSeq = Sequences::WalkingLeft;
	}
	else if (vel.y < 0)
	{
		CurrSeq = Sequences::WalkingUp;
	}
	else if (vel.y > 0)
	{
		CurrSeq = Sequences::WalkingDown;
	}
	else
	{
		if (CurrSeq == Sequences::WalkingRight)
			CurrSeq = Sequences::StandingRight;
		else if (CurrSeq == Sequences::WalkingLeft)
			CurrSeq = Sequences::StandingLeft;
		else if (CurrSeq == Sequences::WalkingUp)
			CurrSeq = Sequences::StandingUp;
		else if (CurrSeq == Sequences::WalkingDown)
			CurrSeq = Sequences::StandingDown;

	}
}
