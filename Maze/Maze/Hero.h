#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
#include "Monster.h"
#include "Item.h"

using namespace std;
#pragma once
class Hero : public Character
{
private:

	//Private Function
	bool checkWeaponHealth();		//Checks if the weapon is broken or not.

	//Private Varaible
	int ID;
	int size;
	int defaultDamage;
	Item* mazeKey;			//A key in the maze.
	Item* emptyHand;		//Indicates no weapon equipped.
	Item* inventory[5];		//Inventory to store items. 

public:
	Hero();
	~Hero();

	//Public Function
	void pickObject(Item*);		//Picks up an object from the maze.
	bool checkInventory(Item*);		//Checks to see the item is in the inventory or not.
	void useItem(Item*);		//Uses the items.
	void fight(Monster*);		//Fights a monster.
	void cleanInventory();		//Clean inventory.
	int getID();		//Returns the hero's ID.

	//Public Varaible
	Item* weapon;
	bool weaponEquipped;

};
