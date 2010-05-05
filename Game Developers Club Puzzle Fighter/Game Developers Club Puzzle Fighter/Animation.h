#pragma once
#include "..\include\SDL.h"

class Animation
{
private:
	int currentKeyFrame;
	int maxKeyFrame;
	SDL_Surface * animationSheet;
	//TODO: check through vaganov's sprite maker for animation storage
public:
	Animation();
	//TODO: make a parameterized constructor that can pull a single animation from a file
};