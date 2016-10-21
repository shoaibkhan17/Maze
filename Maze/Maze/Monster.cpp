#include "Monster.h"

//################################################## CONSTRUCTOR ##############################################################
Monster::Monster()
{
	//Sets varaibles to default values.
	myColour = 268;
	symbol = "-_-";
	monsterID = 0;
	moved = false;
}

//################################################## CUSTOMIZED CONSTRUCTOR ##############################################################
Monster::Monster(string newName, string newSymbol, int newHeath, int newMaxHP, int newDamage, int newID)
{
	//Sets variables to customized values.
	myColour = 268;
	symbol = newSymbol;
	name = newName;
	heath = newHeath;
	maxHP = newMaxHP;
	damage = newDamage;
	monsterID = newID;
}

//################################################## GET ID ##############################################################
int Monster::getID()
{
	return monsterID;		//Returns the monster's ID.
}

//################################################## SET ID ##############################################################
void Monster::setID(int newID)
{
	monsterID = newID;			//Sets the monster's ID.
}

//################################################## DESTRUCTOR ##############################################################
Monster::~Monster()
{
}
