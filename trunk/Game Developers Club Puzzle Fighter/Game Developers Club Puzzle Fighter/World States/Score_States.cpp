#include "Score_States.h"

Score_States* Score_States::Ins()
{
	static Score_States instance;
	return & instance;
}

void Score_States::begin()
{
}

void Score_States::update(int msPassed)
{
}

void Score_States::draw()
{
}

void Score_States::input(SDL_Event e)
{
}

void Score_States::exit()
{
}