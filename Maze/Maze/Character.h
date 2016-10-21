#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#pragma once
class Character
{
public:
	Character();
	~Character();

	//Public Varaibles
	int heath, damage, myColour;		
	string name;
	string symbol;
};

