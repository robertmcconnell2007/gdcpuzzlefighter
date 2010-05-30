#pragma once
#include "World_States Core.h"

class Score_States : public World_State
{
protected:
public:
	static Score_States * Ins();
	void begin();
	void update(int msPassed);
	void draw();
	void input(SDL_Event e);
	void exit();
};