#pragma once
#include <stdlib.h>
#include "World_States Core.h"

#define NO_ACTION   0
#define CLEAR_BOCKS 1
#define END_SCORING 2
#define CHAIN_SCORE 3
#define BOMB_BLASTS 4
#define SUPERPOWERS 5

const int POINTS_CLEARBLOCK = 10;
const int POINTS_BOMBBLASTS = 500;
const int CHAIN_SCORE = 50;

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
	// this is the current scoring mechanic
	unsigned int m_scoreState;
protected:
public:
	static Score_States * Ins();
	void begin();
	void update(int msPassed);
	void draw();
	void input(SDL_Event e);
	void exit();

	//Accessors and Mutators
	void setState(unsigned int a_state){scoreState = a_state;}
};