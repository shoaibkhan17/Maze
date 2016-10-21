#include "Item.h"

//################################################## DEFAULT CONSTRUCTOR ##############################################################
Item::Item()
{
}

//################################################## CUSTOMIZED CONSTRUCTOR ##############################################################
Item::Item(string newName, int newID, int newDamageInc, int newHealthInc, int newUsage)
{
	//Sets all the variables to a customized value.
	name = newName;
	ID = newID;
	damageInc = newDamageInc;
	healthInc = newHealthInc;
	usage = newUsage;
}

//################################################## GET ID ##############################################################
int Item::getID()
{
	return ID;			//Returns the item's ID.
}

//################################################## DESTRUCTOR ##############################################################
Item::~Item()
{
}
