#pragma once
#include <string>
#include "Animation.h"

//////////////////////
////NOTE: This setup, with the animations, may change based
////on how Vanagnov stores the animation files, we shall see.

class Character
{
private:
	//do we need this?
	int comboMultiplyer;
	//TODO: add animation to char
	//don't forget, if we new any of these, delete them in the deconstructor
	Animation * attack1Anim, * attack2Anim, * attack3Anim;
	Animation * idleAnim, * damagedAnim, * loseAnim, * winAnim;
	Animation * currentAnim;
	//special stats?
	//any other parameters?
public:
	Character();
	//TODO: Add a parameterized constructor that takes filenames for the spritesheet and animations
	//Character(string bitmap, string animationSet);
};