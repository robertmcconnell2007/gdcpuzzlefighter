#include "Game Data Handler.h"

GDH * GDH::Ins()
{
	static GDH instance;
	return & instance;
}

GDH::GDH()
{
	curr_State = NULL;
	gameRunning = true;
	//TODO: load core information from ini file, i.e. resolution etc
	//make screen and all that jazz for now will just use some magic numbers

	screen = SDL_SetVideoMode(860, 640, 32, SDL_SWSURFACE);
}

GDH::~GDH()
{
	curr_State = NULL;
	//clear away anything we made
}

bool GDH::changeState(World_State * newState)
{
	if(curr_State)
		curr_State->exit();
	curr_State = newState;
	curr_State->begin();
	return true;
}

void GDH::update(int msPassed)
{
	if(curr_State)
		curr_State->update(msPassed);
	//if there are any global updates
	//they belong here below curr_State->update();
}

void GDH::draw()
{
	if(curr_State)
		curr_State->draw();
	//if there is any global things to be drawn
	//they belong here

	//flip the screen
	if(SDL_Flip(screen) == -1)
		return;
}

void GDH::input()
{
	if(curr_State)
		curr_State->input(e);
	//if there are any global checks for input, they belong here
	if(e.type == SDL_QUIT)
	{
		gameRunning = false;
	}
}
