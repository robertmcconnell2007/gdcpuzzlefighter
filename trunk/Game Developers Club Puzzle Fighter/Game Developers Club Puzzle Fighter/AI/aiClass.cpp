#include "aiClass.h"

void AI::setNewAI(int DIFFICULTY, int BEHAVIOR)
{
	int b = BEHAVIOR;
	then = SDL_GetTicks();
	difficulty = DIFFICULTY * 1000;
	if(behavior != 0)
	{
		delete behavior;
	}
	// behaviors
	if(b == eBasicBehavior)
	{
		behavior = new basicBehavior();
	}
	// TODO: add more behaviors
}
void AI::update()
{
	//if(!behavior->isDone())
	//{
	//	behavior->findSpot();
	//}
	//else
	//{
	//	int now = SDL_GetTicks();
	//	int timePassed = now-then;
	//	if(timePassed > delay)
	//	{
	//		then = now;
	//		// TODO: put in algolrithm to move piece to desired position and rotation
	//		int x = GamePlay::Ins()->getPiece(PLAYER)->getX();
	//		if(behavior->getLoc().x > x)
	//		{
	//			moveReady = true;
	//			move = eP1Right; //TODO: set these to p2 when second game board is ready
	//		}
	//		else if(behavior->getLoc().x < x)
	//		{
	//			moveReady = true;
	//			move = eP1Left; //TODO: set these to p2 when second game board is ready
	//		}
	//		else
	//		{
	//			moveReady = true;
	//			move = eP1Left; //TODO: set these to p2 when second game board is ready
	//		}
	//	}
	//}
}
AI::~AI()
{
	if(behavior != 0)
	{
		delete behavior;
	}
}