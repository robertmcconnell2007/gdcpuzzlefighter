#include <iostream>
#include <string>
#include <ctime>
#include "..\include\SDL.h"
//TODO: true type font .h isn't loading properly, fix it
#include "SDL_ttf.h"	// true-type font library for SDL
#include "Game Data Handler.h"
#include "World States/World_States Core.h"
#include "AI/aiClass.h"
using namespace std;


int main(int argc, char ** argv)
{
	srand((unsigned)time(0));
	if(SDL_Init( SDL_INIT_EVERYTHING) == -1)
	{
		return 1;
	}
	if(TTF_Init() != 0)
	{
		printf("could not initialize True Type Fonts\n");
		return 2;
	}

	Uint32 then = SDL_GetTicks(), now;
	int msPassed = 0;
	int gameUpdateClock = 0;
	int gameDrawClock = 0;

	if ( GDH::Ins()->Initialize() == false )// Initialize the GDH singleton
	{
		cout << "GDH::Initialize failed. Aborting... " << endl;
		return 1;
	}

	while(GDH::Ins()->isGameRunning())
	{
		now = SDL_GetTicks();
		msPassed = now - then;
		then = now;
		gameUpdateClock += msPassed;
		gameDrawClock += msPassed;

		//handle events as soon as they happen
		if(SDL_PollEvent(GDH::Ins()->checkEvent()))
		{
			GDH::Ins()->input();
		}

		//we should update 60 times a second
		if(gameUpdateClock > 16)
		{
			GDH::Ins()->update(gameUpdateClock);
			gameUpdateClock = 0;
		}

		//we should draw 30 times a second
		if(gameDrawClock > 33)
		{
			GDH::Ins()->draw();
			gameDrawClock = 0;
			if(SDL_Flip(GDH::Ins()->getScreen()) == -1)
				return 1;
		}
	}
	//exit SDL_TTF
	TTF_Quit();
	//close out sdl
	SDL_Quit();
	return 0;
}