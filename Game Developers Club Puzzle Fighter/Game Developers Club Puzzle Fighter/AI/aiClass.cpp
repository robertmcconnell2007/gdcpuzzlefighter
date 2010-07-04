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
int AI::getMove()
{
	moveReady = false;
	return move;
}
void AI::update()
{
	if(!(currentPiece == *GamePlay::Ins()->getBoard(1)->getPiece()))
	{
		currentPiece = *GamePlay::Ins()->getBoard(1)->getPiece();
		piecePlaced();
	}
	if(!behavior->isDone())
	{
		behavior->findSpot();
	}
	else
	{
		double now = SDL_GetTicks();
		double timePassed = now-then;
		if(timePassed > delay)
		{
			then = now;
			// TODO: put in algolrithm to move piece to desired position and rotation
			int x = GamePlay::Ins()->getBoard(1)->getPiece()->getX();
			if(behavior->getLoc()->getD() != currentPiece.getD())
			{
				if(currentPiece.getD() - behavior->getLoc()->getD() > (behavior->getLoc()->getD()+4) - (currentPiece.getD()+4))
				{
					moveReady = true;
					move = eInputRotateC;
				}
				else
				{
					moveReady = true;
					move = eInputRotateCC;
				}
			}
			if(behavior->getLoc()->getX() > x)
			{
				moveReady = true;
				move |= eInputRight;
			}
			else if(behavior->getLoc()->getX() < x)
			{
				moveReady = true;
				move |= eInputLeft;
			}
			else
			{
				moveReady = true;
				move |= eInputDown;
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