#include "behaviorClass.h"
#include <iostream>
using namespace std;

class pos;

behaviorParent::behaviorParent()
{
	finished = false;
	iterator = 0;
//	desiredPos = new pieceClass();
}
behaviorParent::~behaviorParent()
{
//	delete [] desiredPos;
}
////////////////////////////////
// basic behavior definitions //
////////////////////////////////

void basicBehavior::findSpot()
{
	//pos.x = iterator % 6;
	//pos.y = 14;
	//pos.d = 0;
	desiredPos.set(iterator % 6, 14, 2);
	iterator++;
	finished = true;
	return;
}