#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
#include "Maze.h"
#include "Monster.h"
#include "stack.h"

using namespace std;

#pragma once

class Game
{
public:
	Game();
	~Game();

	//Public funtions
	void setMazeSize(int);		//Sets the constant array size that holds the maze structure. 
	void playGame();		//Starts the game

private:
	
	//Private functions
	string returnString(string);	//Function the return ascii characters for the welcome fucntion.
	void addDirections();		//Adds directions to the stack.
	void initializeStack();		//Initializes the stack.
	void autoMove();			//A function that auto moves the hero until he loses or wins the game.
	void move(int, int);		//A function to get the direction in which the hero is going to move towards.
	void refresh(string);		//Clears the screen. Then displays the maze and the HUD.
	void findMonster();			//A function that finds the monster and then passes it to moveMonster function to get it moved.
	void moveMonster(Monster*, int, int);		//A function that moves each monster in the maze one by one.
	void welcome(int time);			//Displays the lengend. Basically a welcome screen.
	void displayText(string, string, int, string, int);		//Takes in strings from the welcome function to display them one by one.
	void checkMonsterHealth(Monster*, int, int);		//Checks to see if the monster is dead or alive.
	void findHeroPosition();		//Find the hero in the maze and stores his location. 
	void initializeVisited();		//Sets all the visited spots in the visited array to not visited.
	void initializeValues();		//Sets all the variables to its default values when the user wants to play again.
	void foundKey();				//A function that is called when the hero finds the key in the maze. (ONLY FOR AUTOSOLVING).
	bool checkMove(bool);			//Checks to see if it is a valid move or not.
	bool checkLoopMove(bool);		//A checker to see if it is a valid move or not. ONLY WHEN IN LOOP MODE.
	bool checkForMonsters();		//Checks if there is monster in the position the hero is going to move towards.
	bool checkHealth();					//Checks the players health. Returns true if he is alive.
	bool checkMonsterMove(int, int);		//Checks if the monster is moving in a valid position or not.
	bool tryMove(int, int);			//Trys to move in the direction provided by the move function.
	bool playAgain();		//Asks the user if they want to play again or no.
	int option();			//Sets the game types and conditions matching to the user's preference.
	char getKeyPress();		//Convers and passes the arrow keys to "W","A","S" and "D" according.
	char getStackDirection();		//Gets and passes the direction from the stack for the autosolver to move towards.

	//Private Varaibles
	Maze myMaze;			//An object of type maze
	Stack *mainStack;		//Main stack to move the hero automatically.
	Stack *backStack;		//Back stack to make the reverse move(s).
	int mazeSize, gameType, totalPaths;		
	bool gameOver;
	char direction;
	string condition;

	const char up = 'w';		//"W" is to go up.
	const char down = 's';		//"S" is to go down.
	const char left = 'a';		//"A" is to go left.
	const char right = 'd';		//"D" is to go right
	const char back = 'b';		//"B" indicates if it a back move.
};

