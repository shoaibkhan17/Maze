#include "Hero.h"

//################################################## CONSTRUCTOR ##############################################################
Hero::Hero()
{
	//Sets the varaible to default values.
	symbol = "*_*";
	myColour = 267;
	ID = 4;
	defaultDamage = 4;
	size = 0;
	weaponEquipped = false;

	//Initialzes the pointers.
	mazeKey = new Item;
	weapon = new Item;
	emptyHand = new Item("Hand", 0, 0, 0, 0);

	for (int i = 0; i < 5; i++)
	{
		inventory[i] = new Item;
	}
}

//################################################## CHECK WEAPON HP ##############################################################
bool Hero::checkWeaponHealth()
{
	if (weapon != emptyHand)		//If the hero's weapon is equipped or not.
	{
		if (weapon->usage <= 0)		//If the weapon is used more than specific usaged provided.
		{
			return true;		//If yes, return true.
		}
	}

	else
	{
		return false;		//or else, return false.
	}
}

//################################################## FIGHT ##############################################################
void Hero::fight(Monster * myMonster)
{
	if (weaponEquipped)			//If the weapon is equipped.
	{
		weapon->usage--;	//Decrease the amount of times it can be used.
	}

	heath -= myMonster->damage;		//Decreases the monster's HP depending on the hero's damage.
	myMonster->heath -= damage;		//Decreases the hero's HP depending on the monster's damage.

	if (checkWeaponHealth())		//Checks if the weapon has any uses remaining or not.
	{
		weaponEquipped = false;		//If the weapon is used up, then state no weapon equipped.
		weapon = emptyHand;			//Destroy the weapon, make it as same as fist punch.
		damage = defaultDamage;		//Restore back to the original damage.
	}
}

//################################################## PICK OBJECT ##############################################################
void Hero::pickObject(Item *newItem)
{
	inventory[size] = newItem;		//Picks up an item and save it in a position in the array.
	size++;		//Increases the position in the array to store other items.
}

//################################################## USE ITEM ##############################################################
void Hero::useItem(Item *myItem)
{
	heath += myItem->healthInc;			//Increases the HP by the item's HP increase value.
	damage += myItem->damageInc;		//Increases the HP by the item's damage increase value.
}

//################################################## CHECK INVENTORY ##############################################################
bool Hero::checkInventory(Item *checkItem)
{
	for (int i = 0; i < 5; i++)
	{
		if (inventory[i] == checkItem)			//Checks if the item is located in the inventory or not.
		{
			return true;			//If yes, return true.
		}
	}

	return false;		//Or else return false.
}

//################################################## CLEAN INVENTORY ##############################################################
void Hero::cleanInventory()
{
	for (int i = 0; i < 5; i++)
	{
		inventory[i] = new Item("",0,0,0,0);			//Cleans the inventory.
	}
}

//################################################## GET ID ##############################################################
int Hero::getID()
{
	return ID;			//Returns the hers's ID.
}

//################################################## DESTRUCTOR ##############################################################
Hero::~Hero()
{
}
