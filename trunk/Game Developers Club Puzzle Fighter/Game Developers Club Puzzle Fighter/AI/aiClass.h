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
	AI(): then(0) {}
	~AI();
	behaviorParent *behavior;
	bool moveReady;
	int move;
	int difficulty;
	int delay;
	double then;
public:
	bool isReady() { return moveReady; }
	bool isBready() { return behavior->isDone(); }
	int getMove();
	void piecePlaced() { behavior->notDone(); } //TODO: run when piece has been placed and after counter pieces have been dropped
	void newPiece();
	void setNewAI(int DIFFICULTY, int BEHAVIOR);
	void update();
	static AI* Ins()
	{
		static AI instance;
		return &instance;
	}
};