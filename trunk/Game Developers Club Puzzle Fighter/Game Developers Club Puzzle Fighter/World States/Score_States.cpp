#include "Score_States.h"
#include <stdlib.h>
#include <stdio.h>
#include "SDL_ttf.h"

Score_States* Score_States::Ins()
{
	static Score_States instance;
	return & instance;
}

void Score_States::begin()
{
	//set total score to zero;
	m_totalScore = m_oldScore = 123456789;

	// create our score strings
	m_oldTextScore = new char[MAX_SCORE_WITDH];
	m_textScore = new char[MAX_SCORE_WITDH];

	m_font = TTF_OpenFont("Impressed Metal.ttf",30);

	//store our animated sprite
	//m_snowSurface = load_my_image("World Assets/snowSprite.bmp");

	m_textColor.r = 255;
	m_textColor.g = 255;
	m_textColor.b = 255;
}

void Score_States::update(int msPassed)
{
	//save current score before modification
	//m_oldScore = m_totalScore;
}

void Score_States::draw()
{
	/*
	The score will draw the old score
							snow on the screen
							the new score.
	*/
	SDL_Surface * t_buffer;
	if(m_oldScore == m_totalScore)
	{
		SDL_Surface * t_surface;
		t_buffer = GDH::Ins()->getScreen();
		_itoa_s(m_oldScore, m_oldTextScore, MAX_SCORE_WITDH, 10);
		t_surface = TTF_RenderText_Solid(m_font, m_oldTextScore,m_textColor);
		m_oldTextRect.w = t_surface->w;
		m_oldTextRect.h = t_surface->h;
		drawATile(t_surface,&m_oldTextRect,0,t_buffer,0,320);
		SDL_FreeSurface(t_surface);
	}
	// this will do a transition effect
	//else
	//{
	//	SDL_Surface * t_surface;
	//	t_buffer = GDH::Ins()->getScreen();
	//	_itoa_s(m_oldScore, m_oldTextScore, 9, 10);
	//	_itoa_s(m_totalScore,m_textScore,MAX_SCORE_WITDH,10);
	//	t_surface = TTF_RenderText_Solid(m_font, m_oldTextScore,m_textColor);
	//	m_oldTextRect.w = t_surface->w;
	//	m_oldTextRect.h = t_surface->h;
	//	drawATile(t_surface,&m_oldTextRect,0,t_buffer,0,320);
	//	t_surface = TTF_RenderText_Solid(m_font, m_textScore, m_textColor);
	//	m_textRect.w = t_surface->w;
	//	m_textRect.h = t_surface->h;
	//	SDL_Rect t_rect = {0,0,154,31};
	//	for(int i = 0; i < SNOW_FRAMES; ++i)
	//	{
	//		t_rect.x = i * SNOW_WIDTH;
	//		drawATile(m_snowSurface, &t_rect, i, t_buffer, 0, 320);
	//	}
	//	drawATile(t_surface,&m_textRect,0,t_buffer,0,320);
	//	SDL_FreeSurface(t_surface);
	//}
	SDL_FreeSurface(t_buffer);
}

void Score_States::input(SDL_Event e)
{
}

void Score_States::exit()
{
	delete[] m_oldTextScore;
	delete[] m_textScore;
	//SDL_FreeSurface(m_snowSurface);
}