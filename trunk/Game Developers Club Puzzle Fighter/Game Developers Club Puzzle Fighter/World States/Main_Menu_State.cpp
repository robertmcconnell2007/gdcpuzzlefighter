#include "Main_Menu_State.h"

////////////////////////////////////////////////////
///////////////////Main Menu////////////////////////
////////////////////////////////////////////////////

Main_Menu* Main_Menu::Ins()
{
	static Main_Menu instance;
	return & instance;
}

void Main_Menu::begin()
{
	backgroundSurface = load_my_image("World Art Assets/Main Menu Background 1.bmp");
	menuButtons = load_my_image("World Art Assets/menuButtons.bmp");
	BGSRect = GDH::Ins()->getScreen()->clip_rect;
	optionsRect.h = playRect.h = quitRect.h = 75;
	optionsRect.w = playRect.w = quitRect.w = 100;
	optionsRect.y = playRect.y = quitRect.y = BGSRect.h - 100;
	optionsRect.x = 100;
	playRect.x = 300;
	quitRect.x = 500;
}

void Main_Menu::update(int msPassed)
{
}

void Main_Menu::draw()
{
	drawATile(backgroundSurface, &BGSRect, 0, GDH::Ins()->getScreen(), BGSRect.x, BGSRect.y);
	drawATile(menuButtons, &optionsRect, 1, GDH::Ins()->getScreen(), optionsRect.x, optionsRect.y);
	drawATile(menuButtons, &playRect, 0, GDH::Ins()->getScreen(), playRect.x, playRect.y);
	drawATile(menuButtons, &quitRect, 2, GDH::Ins()->getScreen(), quitRect.x, quitRect.y);
}

void Main_Menu::input(SDL_Event e)
{
}

void Main_Menu::exit()
{
	SDL_FreeSurface(backgroundSurface);
	SDL_FreeSurface(menuButtons);
}