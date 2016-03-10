#include "fighter.h"

#include <iostream>

using namespace std;

Fighter::Fighter(string name):Player(name)
{
	setName(name);
}

void Fighter::doAction(Player* target)
{
	target->setHP(target->getHP() - 75);
	if(target->getHP() < 0)
	{
		target->isDead();
	}
}