#include <cstdlib>
#include <string>

using namespace std;

#pragma once
class Item
{
public:
	Item();
	Item(string, int, int, int, int);
	~Item();

	//Public fucntions 
	int getID();

	//Public variables
	string name;
	int ID;
	int damageInc;
	int usage;
	int healthInc;


};

