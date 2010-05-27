#pragma once
#include "behaviorClass.h"
#include "..\..\include\SDL.h"

class AI
{
private:
	AI();
	~AI();
	behaviorParent *behavior;
	bool moveReady;
	int move;
	int difficulty;
	int delay;
	int then;
public:
	bool isReady() { return moveReady; }
	int getMove() { return move; }
	void setNewAI(int DIFFICULTY, int BEHAVIOR);
	void update();
	static AI* Ins()
	{
		static AI instance;
		return &instance;
	}
};