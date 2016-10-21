#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"

using namespace std;

#pragma once
class Monster : public Character
{

private:
	//Private Varaible.
	int monsterID;

public:
	Monster();
	Monster(string, string, int, int, int, int);
	~Monster();

	//Public functions.
	void setID(int);		//Sets the monster's ID.
	int getID();			//Returns the monster's ID.

	//Public variables.
	bool moved;			//A varaible that states if the monster has moved or not.
	int maxHP;			//A varaible that states the initial HP of the monster. (MAX HP)
};

