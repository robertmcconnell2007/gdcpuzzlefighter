#pragma once
//#include "..\World States\Main_Game_State.h"

//class pieceClass;

class pos
{
private:
	int x, y, d;
public:
	int getX() {return x;}
	int getY() {return y;}
	int getD() {return d;}
	void set(int nx, int ny, int nd) { x = nx; y = ny; d = nd;}
};

class behaviorParent	// this is the parent class for the behavior classes
{
protected:
	bool finished;		// has found a position for the piece
	int iterator;		// used for when the find spot function takes too long to calculate
	pos desiredPos;	// the desired position based on the behavior
public:
	//behaviorParent() { finished = false; iterator = 0; }
	behaviorParent();
	~behaviorParent();
	bool isDone() { return finished; }	// will return true when the desired position has been found
	void notDone() { finished = false; } // run this when a new desired position needs to be found
	pos* getLoc() { return &desiredPos; }	// returns the position and orientation of the piece as a struct. x, y, and r(otation)
	virtual void findSpot() = 0;	// the function to find the desired position of the piece based on the behavior
};

class basicBehavior : public behaviorParent // testing to see if I even remember how this works
{
private:
public:
	void findSpot();
};