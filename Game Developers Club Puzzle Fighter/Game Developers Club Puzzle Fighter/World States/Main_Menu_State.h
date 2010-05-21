#pragma once
#include "World_States Core.h"

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