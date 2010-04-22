#pragma once
#include <vector>
#include "SDL.h"
#include "..\Character.h"
using namespace std;

/*
copy paste this and change [name] to create a new state

class [name] : public World_State
{
protected:
	[name]();
	~[name]();
public:
	static [name]* Ins();
	void begin();
	void update(int msPassed);
	void draw();
	void input(SDL_Event e);
	void exit();
};

*/

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


class Choose_Character : public World_State
{
protected:
	//number of playable chars, player ones postion in list, player twos position in list
	int num_chars, list_position_1, list_position_2;
	//need a storage list for playable characters, need a datatype for them.
	vector<Character> playable_chars;
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
};