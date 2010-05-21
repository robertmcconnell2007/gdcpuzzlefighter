#include "Splash_Screen_State.h"

////////////////////////////////////////////////////
/////////////////Splash Screen//////////////////////
////////////////////////////////////////////////////

Splash_Screen* Splash_Screen::Ins()
{
	static Splash_Screen instance;
	return & instance;
}

void Splash_Screen::begin()
{
	splashSurface = load_my_image("World Art Assets/Splash Screen 1.bmp");
	SSRect = GDH::Ins()->getScreen()->clip_rect;
}

void Splash_Screen::update(int msPassed)
{
}

void Splash_Screen::draw()
{
	drawATile(splashSurface, &SSRect, 0, GDH::Ins()->getScreen(), SSRect.x, SSRect.y);
}

void Splash_Screen::input(SDL_Event e)
{
	if(e.key.keysym.sym == SDLK_1)
		GDH::Ins()->changeState((World_State*)Main_Menu::Ins());
}

void Splash_Screen::exit()
{
	SDL_FreeSurface(splashSurface);
}