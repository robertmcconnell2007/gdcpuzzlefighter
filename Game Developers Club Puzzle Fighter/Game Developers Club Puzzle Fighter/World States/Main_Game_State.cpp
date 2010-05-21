#include "Main_Game_State.h"

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