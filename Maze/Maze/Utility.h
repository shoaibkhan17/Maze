#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>

using namespace std;

#pragma once
class Utility
{
public:
	Utility();
	~Utility();


	//Constant colour change codes. 
	static const int playerColour = 267;
	static const int blackColour = 256;
	static const int redColour = 204;
	static const int yellowColour = 238;
	static const int blueColour = 153;
	static const int greenColour = 170;
	static const int goldColour = 102;
	static const int start_end_colour = 249;
	static const int wallColour = 368;
	static const int healthColour = 202;
	static const int healthTitle = 12;
	static const int monsterHPTitle = 13;
	static const int monsterHPColour = 85;
	static const int healthPotion = 252;
	static const int welcomeTitle = 14;
	static const int subColour = 15;
	static const int keyColour = 10;
	static const int swordColour = 240;
	static const int doorColour = 100;

	static void changeColour(int);
};
