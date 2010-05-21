#pragma once
#include "World_States Core.h"

//this is the main function, that will handle all the gameplay stuff
//this is going to be the most complex by far
class GamePlay : public World_State
{
protected:
	//these hold pointers to the two characters to be played this round 
	Character *player1, *player2;
	//TODO: add sdl_surfaces and rects for the background and border art, etc
	//TODO: add custom classes to handle the tetris games
	//TODO: add animation variables to hold whatever animations the design team comes up with
public:
	static GamePlay * Ins();
	void begin();
	void update(int msPassed);
	void draw();
	void input(SDL_Event e);
	void exit();
};