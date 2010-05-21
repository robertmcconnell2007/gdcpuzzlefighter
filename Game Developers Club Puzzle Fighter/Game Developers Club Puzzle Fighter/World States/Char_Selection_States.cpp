#include "Char_Selection_States.h"

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