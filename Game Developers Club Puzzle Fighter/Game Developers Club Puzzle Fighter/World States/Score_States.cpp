#include "Score_States.h"

Score_States* Score_States::Ins()
{
	static Score_States instance;
	return & instance;
}

void Score_States::begin()
{
	//set total score to zero;
	m_totalScore = m_oldScore = 0;

	//set text to NULL
	m_textScore = NULL;
}

void Score_States::update(int msPassed)
{
	//save current score before modification
}

void Score_States::draw()
{
	/*
	The score will draw the old score
							snow on the screen
							the new score.
	*/
}

void Score_States::input(SDL_Event e)
{
}

void Score_States::exit()
{
}