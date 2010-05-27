#include "aiClass.h"

void AI::setNewAI(int DIFFICULTY, int BEHAVIOR)
{
	int b = BEHAVIOR;
	then = SDL_GetTicks();
	difficulty = DIFFICULTY * 1000;
	if(b == 0)
	{
		if(behavior != 0)
		{
			delete behavior;
		}
		behavior = new basicBehavior();
	}
}
void AI::update()
{
	if(!behavior->isDone())
	{
		behavior->findSpot();
	}
	else
	{
		int now = SDL_GetTicks();
		int timePassed = now-then;
		if(timePassed > delay)
		{
			then = now;
			// TODO: put in algolrithm to move piece to desired position and rotation
		}
	}
}
AI::~AI()
{
	if(behavior != 0)
	{
		delete behavior;
	}
}