#pragma once
#include <stdlib.h>
#include "World_States Core.h"

class Score_States : public World_State
{
private:
	/*
	this is the string that will hold the current score
	and display it on screen
	*/
	char* m_textScore;
	// this is the total score for the player
	unsigned int m_totalScore;
	// this hold the images needed to display
	SDL_Surface * m_textSurface;
	// this holds the rect to blit to surface
	SDL_Rect m_textRect;
protected:
public:
	static Score_States * Ins();
	void begin();
	void update(int msPassed);
	void draw();
	void input(SDL_Event e);
	void exit();
};