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
/////////////Choose Char States/////////////////////
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
	//playable_chars
}

void Choose_Character::load_playable_chars()
{
	//loop and populate the list of playable characters
}