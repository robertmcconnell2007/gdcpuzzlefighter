#include "Score_States.h"
#include <stdlib.h>
#include <stdio.h>
#include "SDL_ttf.h"
//#include "Game Data Handler.h"

Score_States* Score_States::Ins()
{
	static Score_States instance;
	return & instance;
}

void Score_States::begin()
{
	//set total score to zero;
	m_totalScore = m_oldScore = 0;

	// set x & y of rect
	m_oldTextRect.x = 0;
	m_oldTextRect.y = 640 / 2;

	// create outr score strings
	m_oldTextScore = new char[9];
	m_textScore = new char[9];

	m_font = TTF_OpenFont("Impressed Metal.ttf",20);

	m_textColor.r = 255;
	m_textColor.g = 0;
	m_textColor.b = 0;
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
	if(m_oldScore == m_totalScore)
	{
		SDL_Surface * t_surface, * t_buffer;
		t_buffer = GDH::Ins()->getScreen();
		_itoa_s(m_oldScore, m_oldTextScore, 9, 10);
		t_surface = TTF_RenderText_Solid(m_font, m_oldTextScore,m_textColor);
		m_oldTextRect.w = t_surface->w;
		m_oldTextRect.h = t_surface->h;
		SDL_BlitSurface(t_buffer,NULL,t_surface,&m_oldTextRect);
		SDL_FreeSurface(t_surface);
		SDL_FreeSurface(t_buffer);
	}
}

void Score_States::input(SDL_Event e)
{
}

void Score_States::exit()
{
}