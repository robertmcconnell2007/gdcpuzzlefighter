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
	arb_img = load_my_image("..\\btn_dark_over.bmp");
	img_rect.x = 5;
	img_rect.y = 10;
	img_rect.w = 100;
	img_rect.h = 50;
}

void Choose_Character::update(int msPassed)
{
}

void Choose_Character::draw()
{
	//apply_surface(img_rect.x, img_rect.y, arb_img, GDH::Ins()->getScreen());
	drawATile(arb_img, &img_rect, 0, GDH::Ins()->getScreen(), img_rect.x, img_rect.y);
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
