#pragma once
#include "World States\World_States Core.h"
#include "Character.h"
using namespace std;

//GDH -> Game Data Handler
class GDH
{
private:
	GDH();
	~GDH();
	World_State * curr_State;
	SDL_Event e;
	SDL_Surface * screen;
	//tells whether the game is running
	bool gameRunning;
	//need a pair of characters that can be used 
	Character current_chars[2];
	//need to store the world space to be used
	//environment  current_envrmt;
public:
	SDL_Surface * getScreen() {return screen;}
	SDL_Event* checkEvent() {return &e;}
	bool isGameRunning() {return gameRunning;}
	void endGame()       {gameRunning = false;}
	
	static GDH * Ins();
		
	bool changeState(World_State * newState);
	void update(int msPassed);
	void draw();
	void input();
	
};