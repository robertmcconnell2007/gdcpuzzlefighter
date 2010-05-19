#pragma once
#include <vector>
#include "..\..\include\SDL.h"
#include "..\Character.h"
#include "..\graphicsloader.h"
using namespace std;

class GDH;
#include "..\Game Data Handler.h"
/*
copy paste this and change [name] to create a new state
all states have six basic funtions. ins is how you access the singleton (i.e. WorldState::Ins()->something)
begin is called upon entry to the state, exit upon leaving the state
the other three are called every time the game loops

class [name] : public World_State
{
protected:
public:
	static [name] * Ins();
	void begin();
	void update(int msPassed);
	void draw();
	void input(SDL_Event e);
	void exit();
};

*/

//this is the core parent class that the others are derived from
//pure virtual
class World_State
{
protected:
	World_State();	
public:
	static World_State* Ins();
	virtual void begin() = 0;
	virtual void update(int msPassed) = 0;
	virtual void draw() = 0;
	virtual void input(SDL_Event e) = 0;
	virtual void exit() = 0;
	~World_State();
};

class Splash_Screen : public World_State
{
protected:
	SDL_Surface * splashSurface;
	SDL_Rect SSRect;
public:
	static Splash_Screen * Ins();
	void begin();
	void update(int msPassed);
	void draw();
	void input(SDL_Event e);
	void exit();
};

class Main_Menu : public World_State
{
protected:
	SDL_Surface * backgroundSurface;
	SDL_Surface * menuButtons;
	SDL_Rect BGSRect;
	SDL_Rect optionsRect;
	SDL_Rect quitRect;
	SDL_Rect playRect;
public:
	static Main_Menu * Ins();
	void begin();
	void update(int msPassed);
	void draw();
	void input(SDL_Event e);
	void exit();
};


class Choose_Character : public World_State
{
protected:
	//number of playable chars, player ones postion in list, player twos position in list
	int num_chars, list_position_1, list_position_2;
	//storage list for playable characters
	vector<Character*> playable_chars;
	//TODO: add surfaces and rects to handle all the menu and background stuff
public:
	//parent functions
	static Choose_Character* Ins();
	void begin();
	void update(int msPassed);
	void draw();
	void input(SDL_Event e);
	void exit();
	//personal functions
	//this function will pull in the list of playable characters
	void load_playable_chars();
	void deload_playable_chars();
};


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