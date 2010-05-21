#pragma once
#include <vector>
#include "..\..\include\SDL.h"
#include "..\Character.h"
#include "..\graphicsloader.h"
using namespace std;

class GDH;
#include "..\Game Data Handler.h"

//#include's for other state.h files at bottom!!!!



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



#include "Main_Menu_State.h"
#include "Char_Selection_States.h"
#include "Main_Game_State.h"
#include "Main_Menu_State.h"
#include "Options_State.h"
#include "Score_States.h"
#include "Splash_Screen_State.h"



