#include "aiClass.h"

void AI::setNewAI(int DIFFICULTY, int BEHAVIOR)
{
	int b = BEHAVIOR;
	then = SDL_GetTicks();
	difficulty = DIFFICULTY * 250;
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
int AI::getMove()
{
	moveReady = false;
	return move;
}
void AI::update()
{
	if(!behavior->isDone())
	{
		behavior->findSpot();
	}
	else
	{
		if(GamePlay::Ins()->getBoard(1)->getPiece()->isNew())
			piecePlaced();
		double now = SDL_GetTicks();
		double timePassed = now-then;
		if(timePassed > difficulty)
		{
			then = now;
			// TODO: put in algolrithm to move piece to desired position and rotation
			int x = GamePlay::Ins()->getBoard(1)->getPiece()->getX();
			if(behavior->getLoc()->getD() != GamePlay::Ins()->getBoard(1)->getPiece()->getD())
			{
				int d = GamePlay::Ins()->getBoard(1)->getPiece()->getD() - behavior->getLoc()->getD();
				d = abs(d);
				if(d > 3)
				{
					moveReady = true;
					move = eInputRotateCC;
				}
				else
				{
					moveReady = true;
					move = eInputRotateC;
				}
			}
			else if(behavior->getLoc()->getX() > x)
			{
				moveReady = true;
				move = eInputRight;
			}
			else if(behavior->getLoc()->getX() < x)
			{
				moveReady = true;
				move = eInputLeft;
			}
			else
			{
				moveReady = true;
				move = eInputDown;
			}
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