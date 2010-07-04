#pragma once
#include "..\World States\Main_Game_State.h"
#include "behaviorClass.h"
#include "..\..\include\SDL.h"

enum eBehaviors // format for enums is e followd by the name of your function ex eBasicBehavior
{
	eBasicBehavior,
};

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
	int getMove() { moveReady = false; return move; }
	void piecePlaced() { behavior->notDone(); } //TODO: run when piece has been placed and after counter pieces have been dropped
	void setNewAI(int DIFFICULTY, int BEHAVIOR);
	void update();
	static AI* Ins()
	{
		static AI instance;
		return &instance;
	}
};