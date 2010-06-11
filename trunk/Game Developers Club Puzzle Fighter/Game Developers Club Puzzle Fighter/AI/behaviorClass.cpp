#include "behaviorClass.h"


////////////////////////////////
// basic behavior definitions //
////////////////////////////////

void basicBehavior::findSpot()
{
	pos.x = iterator % 6;
	pos.y = 14;
	pos.r = 0;
	iterator++;
	return;
}