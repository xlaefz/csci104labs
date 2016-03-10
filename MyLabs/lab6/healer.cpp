#include "healer.h"

#include <iostream>

using namespace std;

Healer:: Healer(string name) : Player(name)
{
	setName(name);
}

void Healer::doAction(Player* target)
{
	int maxhp = target->getMaxHP();
	target->setHP(target->getHP() +75);
	if(target->getHP() > maxhp)
	{
		target->setHP(maxhp);
	}
}