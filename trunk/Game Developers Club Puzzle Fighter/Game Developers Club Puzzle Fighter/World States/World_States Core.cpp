#include "World_States Core.h"

World_State * World_State::Ins()
{
	//static World_State instance;
	//return & instance;
	return NULL;
}

World_State::World_State()
{
}

World_State::~World_State()
{
}

////////////////////////////////////////////////////
////////////////////Template////////////////////////
////////////////////////////////////////////////////
/*
[name]* [name]::Ins()
{
	static [name] instance;
	return & instance;
}

void [name]::begin()
{
}

void [name]::update(int msPassed)
{
}

void [name]::draw()
{
}

void [name]::input(SDL_Event e)
{
}

void [name]::exit()
{
}
*/

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

////////////////////////////////////////////////////
/////////////Choose Char State//////////////////////
////////////////////////////////////////////////////

//Choose_Character::Choose_Character()
//{
//}
//
//Choose_Character::~Choose_Character()
//{
//}

Choose_Character* Choose_Character::Ins()
{
	static Choose_Character instance;
	return & instance;
}

void Choose_Character::begin()
{
	load_playable_chars();
}

void Choose_Character::update(int msPassed)
{
}

void Choose_Character::draw()
{
}

void Choose_Character::input(SDL_Event e)
{
}

void Choose_Character::exit()
{
}

void Choose_Character::load_playable_chars()
{
	//loop and populate the list of playable characters
}

void Choose_Character::deload_playable_chars()
{
	playable_chars.clear();
}

////////////////////////////////////////////////////
/////////////Game Play State////////////////////////
////////////////////////////////////////////////////

GamePlay* GamePlay::Ins()
{
	static GamePlay instance;
	return & instance;
}

void GamePlay::begin()
{
}

void GamePlay::update(int msPassed)
{
}

void GamePlay::draw()
{
}

void GamePlay::input(SDL_Event e)
{
}

void GamePlay::exit()
{
	//playable_chars
}
