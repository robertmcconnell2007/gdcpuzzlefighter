#pragma once
#include <stdlib.h>
#include "World_States Core.h"
#include "SDL_TTF.h"

enum ScoreStateTypes
{
	NO_ACTION,
	CLEAR_BOCKS,
	END_SCORING,
	CHAIN_SCORE,
	BOMB_BLASTS,
	SUPERPOWERS
};

const int MAX_SCORE_WITDH = 12 * 9;
const int POINTS_CLEARBLOCK = 10;
const int POINTS_BOMBBLASTS = 500;
const int POINTS_CHAINS = 50;
const int SNOW_FRAMES = 4;
const int SNOW_WIDTH = 154;

class Score_States : public World_State
{
private:
	/*
	this is the string that will hold the current score
	and display it on screen
	*/
	char* m_textScore;
	char* m_oldTextScore;
	// this is the total score for the player
	unsigned int m_totalScore;
	unsigned int m_oldScore;
	// this hold the images needed to display the score transition
	SDL_Surface * m_snowSurface;
	// text color
	SDL_Color m_textColor;
	// this holds the rect to blit to surface
	SDL_Rect m_textRect;
	SDL_Rect m_oldTextRect;
	// the font
	TTF_Font * m_font;
	// this is the current scoring mechanic
	ScoreStateTypes m_scoreState;

	// Draw Sub function
protected:
public:
	static Score_States * Ins();
	void begin();
	void update(int msPassed);
	void draw();
	void input(SDL_Event e);
	void exit();

	//Accessors and Mutators
	void setState(unsigned int a_state){m_scoreState = (ScoreStateTypes)a_state;}
};