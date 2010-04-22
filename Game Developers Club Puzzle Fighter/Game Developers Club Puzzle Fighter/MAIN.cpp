#include <iostream>
#include <string>
#include "SDL.h"
//#include "SDL_ttf.h"	// true-type font library for SDL
#include "Game Data Handler.h"
using namespace std;


int main(int argc, char ** argv)
{
	if(SDL_Init( SDL_INIT_EVERYTHING) == -1)
	{
		return 1;
	}
	//if(TTF_Init() != 0)
	//{
	//	printf("could not initialize True Type Fonts\n");
	//	return 2;
	//}

	Uint32 then = SDL_GetTicks(), now;
	int msPassed = 0;
	while(GDH::Ins()->isGameRunning())
	{
		now = SDL_GetTicks();
		msPassed = then - now;
		then = now;

		if(SDL_PollEvent(GDH::Ins()->checkEvent()))
		{
			GDH::Ins()->input();
		}

		GDH::Ins()->update(msPassed);

		GDH::Ins()->draw();
	}
	SDL_Quit();
	return 0;
}