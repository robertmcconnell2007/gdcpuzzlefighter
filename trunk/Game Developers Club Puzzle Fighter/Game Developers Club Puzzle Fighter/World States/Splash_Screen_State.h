#pragma once
#include "World_States Core.h"

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