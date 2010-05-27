#pragma once

struct orientation  // this struct contains the orientation of the object
{
	int x;			// x location
	int y;			// y location
	int r;			// 0 is up, 1 is right, 2 is down, 3 is left
};

class behaviorParent	// this is the parent class for the behavior classes
{
protected:
	bool finished;		// has found a position for the piece
	int iterator;		// used for when the find spot function takes too long to calculate
	orientation pos;	// the desired position based on the behavior
public:
	behaviorParent() { finished = false; iterator = 0; }
	bool isDone() { return finished; }	// will return true when the desired position has been found
	orientation getLoc() { return pos; }	// returns the position and orientation of the piece as a struct. x, y, and r(otation)
	virtual void findSpot() = 0;	// the function to find the desired position of the piece based on the behavior
};

class basicBehavior : public behaviorParent // testing to see if I even remember how this works
{
private:
public:
	void findSpot();
};