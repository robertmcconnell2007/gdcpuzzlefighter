#pragma once
#include "World_States Core.h"

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