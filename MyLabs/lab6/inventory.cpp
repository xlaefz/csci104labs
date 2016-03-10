#include "inventory.h"

#include <iostream>

using namespace std;

Inventory::Inventory()
{

}

void Inventory::addItem(string itemname, int amount)
{
	std::map<std::string, int>::iterator it;
	int counter = 0;
	for(it = this->begin( ); it != this->end( ); ++it)
	{
		if(it->first == itemname)
		{
			counter++;

		}
	}
	if(counter == 0)
	{
		insert(make_pair(itemname, amount));
	}
	else
	{
		find(itemname)->second += amount;
	}
}
void Inventory::removeItem(string itemname)
{
	std::map<std::string, int>::iterator it = find(itemname);
	erase(it);
}	/* Return the number of items with this name from the inventory. */

int Inventory::getNumItems(string itemname)
{
	std::map<std::string, int>::iterator it = find(itemname);
	return it->second;
}

void Inventory::printAllItems()
{
	std::map<std::string, int>::iterator it;
	for(it = this->begin( ); it != this->end( ); ++it)
	{
		cout<< it->first << " " <<it->second<<endl;
	}
}