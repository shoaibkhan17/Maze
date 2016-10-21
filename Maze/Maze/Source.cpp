//Author			: Shoaib Khan
//Description		: Maze game with four different time of game modes. 
//Date Creater		: 05/05/16
//Date Modified		: 17/06/16

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include "Game.h"
#include <ctime>

using namespace std;

const int arraySize = 22;			//States the array size

int main()
{
	srand(time(NULL));				//Ignores time while generating a random number.

	Game myGame;							//Creates an object of type Game.
	myGame.setMazeSize(arraySize);			//Sets the size of the array that contains the maze structure.
	myGame.playGame();						//Starts the game.

	cout << endl;
	system("PAUSE");
	return 0;
}