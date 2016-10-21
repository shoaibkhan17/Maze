#include "Game.h"


//################################################## CONSTRUCTOR ##############################################################
Game::Game()
{
	//Sets the variables to default values.
	gameOver = false;
	mainStack = new Stack();
	backStack = new Stack();
	gameType = 0;
	totalPaths = 0;
}

//################################################## SET MAZE SIZE ##############################################################
void Game::setMazeSize(int size)
{
	mazeSize = size;
	myMaze.setSize(size);			//Sets the maze size for the array.
}

//################################################## DISPLAY TEXT ##############################################################
void Game::displayText(string letter, string spacing, int colour, string subText, int time)
{
	cout << spacing;

	Utility::changeColour(colour);			//Changes colour. See Utility class for more details.

	for (auto character : letter)
	{
		cout << character;				//Displays the character one by one from the passed string.
		Sleep(time);
	}

	Utility::changeColour(Utility::subColour);

	cout << subText;			//Displays the sub text.
	cout << endl;

	Utility::changeColour(7);
}

//################################################## RETURN STRING ##############################################################
string Game::returnString(string type)
{
	string symbol = "";

	if (type == "key")			//If it is a key.
	{
		symbol = "o-";
		symbol += char(183);		//Return the key symbol.
	}

	else if (type == "door")		//If it is a door.
	{
		symbol += char(178);
		symbol += char(176);
		symbol += char(178);	//Return the door symbol.
	}

	return symbol;
}

//################################################## WELCOME ##############################################################
void Game::welcome(int time)
{
	//Passes the strings to the display text function to display them character by character.
	displayText("WELCOME TO MAZE RUNNER v1.0", "\n\n\n\n\n\n\n\n    \t\t\t", Utility::welcomeTitle, "", time);		
	cout << endl;
	displayText("--> LEGEND <--", "\t\t\t       ", 13, "", time);
	cout << endl;
	displayText(" S ", "  \t\t\t\t ", Utility::start_end_colour, " - Start", time);
	displayText(" F ", "  \t\t\t\t ", Utility::start_end_colour, " - Finish", time);
	displayText("|+|", "  \t\t\t\t ", Utility::healthPotion, " - Health Potion", time);
	displayText("=--", "  \t\t\t\t ", 10, " - Sword", time);
	displayText(returnString("key"), "  \t\t\t\t ", Utility::keyColour, " - Key", time);
	displayText(returnString("door"), "  \t\t\t\t ", Utility::doorColour, " - Door", time);
	displayText("x_x", "  \t\t\t\t ", myMaze.myMonster.myColour, " - Lucifer", time);
	displayText("!_!", "  \t\t\t\t ", myMaze.myMonster.myColour, " - Zombie", time);
	displayText("@_@", "  \t\t\t\t ", myMaze.myMonster.myColour, " - Vampire", time);
	displayText("&_&", "  \t\t\t\t ", myMaze.myMonster.myColour, " - Warewolf", time);
	displayText("#_#", "  \t\t\t\t ", myMaze.myMonster.myColour, " - Demon", time);
	displayText("%_%", "  \t\t\t\t ", myMaze.myMonster.myColour, " - Bigfoot", time);
	displayText("x_x", "  \t\t\t\t ", myMaze.myMonster.myColour, " - Lucifer", time);

	cout << endl << endl;
}

void Game::initializeValues()
{
	//Sets the variables to default values.
	gameOver = false;
	mainStack = new Stack();
	backStack = new Stack();
	gameType = 0;
	totalPaths = 0;
	myMaze.myHero.cleanInventory();
}

//################################################## PLAY AGAIN ##############################################################
bool Game::playAgain()
{
	string option;
	bool pass = false;

	do
	{
		Utility::changeColour(15);
		cout << endl << "Would you like to play again?" << endl;				//Asks the user if they want to play again or not.
		cout << "1) YES" << endl;
		cout << "2) NO" << endl;
		cin >> option;

		if (option == "1")			//If their response is yes.
		{
			initializeValues();
			return true;		//Return true to play again.
		}

		else if (option == "2")		//If their response is no.
		{
			return false;		//Return false to play again.
		}

		else		//If their response is neither yes or no.
		{ 
			cout << "--> Invalid Option <--" << endl;		//Display invalid option.
			system("CLS");
		}
	} while (pass == false);			//Keep asking again until they enter a valid option. 

}

//################################################## PLAY GAME ##############################################################
void Game::playGame()
{
	do
	{
		system("CLS");
		welcome(50);
		int userOption = option();		//Asks for user's option.
		gameType = userOption;
		refresh("");

		if (userOption == 1)		//If they want to manually play the game.
		{
			do
			{
				move(1, 0);		//Call the move function and set autosolve to false.
				gameOver = checkHealth();		//Check the hero's HP after every turn.
			} while (gameOver == false);		//Keep playing the game until the game is over.
		}

		else		//If they pick autosolve.
		{
			autoMove();		//Call the automove function.
		}
	} while (playAgain());		//After the game is done, ask the user if they want to play again or not.
}

//################################################## AUTO MOVE ##############################################################
void Game::autoMove()
{
	initializeStack();			//Initialize the stack.

	do
	{
		move(2, 0);		//Call the move function and set the autosolver to true.
		Sleep(80);
		gameOver = checkHealth();		//Check the hero's HP after every turn.
	} while (gameOver == false);		//Keep playing the game untill the game is over.
}

//################################################## OPTION ##############################################################
int Game::option()
{
	int time = 50;
	bool pass = false;
	do
	{
		string option;
		Utility::changeColour(15);
		cout << "Would you like to:" << endl;		//Asks the user what game type they would like to pick.
		Utility::changeColour(10);
		cout << "1) Start game" << endl;
		cout << "2) Auto solve" << endl;
		cout << "3) Auto solve with monsters" << endl;
		Utility::changeColour(12);
		cout << "4) loop testing (DEVELOPER ACCESS) [KEY AND DOOR, REQUIRES TIME]" << endl;
		Utility::changeColour(15);
		cout << "Enter your choice (1-4): ";
		Utility::changeColour(7);
		cin >> option;
		system("CLS");		

		if (option == "1")			//If they pick manual game mode.
		{
			myMaze.transferArray(myMaze.manualGame);		//Transfer the manual game array. 
			pass = true;
			return 1;
		}

		else if (option == "2")		//If they pick auto solve mode.
		{
			myMaze.transferArray(myMaze.autoGame1);			//Transfers the auto Game without monsters array.
			pass = true;
			return 2;
		}

		else if (option == "3")		//If they pick auto solve with monsters mode.
		{
			myMaze.transferArray(myMaze.autoGame2);		//Transfer the auto game with monsters array.
			pass = true;
			return 3;
		}

		else if (option == "4")		//Ifthey pick loop testing mode.
		{
			myMaze.transferArray(myMaze.loopTest);			//Transfer the loop testing array with key and door.
			pass = true;
			return 4;
		}

		else
		{
			welcome(0);
			cout << "--> Invalid Option <--" << endl;		//Else displays invalid option.
		}
	} while (pass == false);
}

//################################################## REFRESH ##############################################################
void Game::refresh(string condition)
{
	myMaze.displayMaze();			//Displays the maze.

	if ((gameType == 1) || (gameType == 3))			//If the game mode is manual mode or auto solver with monsters mode. 
	{
		myMaze.displayHUD();		//Then display the HUD.
	}
	cout << endl << condition << endl;		//Pick condition if there is any.

	Utility::changeColour(14);
	if ((gameType == 1) || (gameType == 3))			//If the game mode is manual more or auto solver with monster mode.
	{
		cout << "                                                             HP: " << myMaze.myHero.heath << endl;			//Display the hero's HP
		cout << "                                                   Total Damage: " << myMaze.myHero.damage << endl;		//Display the hero's damage.
	}
	cout << "                                                   Total Paths : " << totalPaths;		//Display total paths moved.
	Utility::changeColour(7);	
}
//################################################## GET KEY PRESS ##############################################################
char Game::getKeyPress()
{
	char key = 127;

	key = _getch();			//Gets the user keyboard input.

	if (key == 0 || key == -32)
	{
		key = _getch();

		if (key == 72)			//If it is a "w" or an up arrow.
		{
			key = 'w';
		}

		else if (key == 75)		//If it is a "a" or a left arrow.
		{
			key = 'a';
		}

		else if (key == 77)		//If it is a "d" or a right arrow.
		{
			key = 'd';
		}

		else if (key == 80)		//If it is a "s" or an down arrow.
		{
			key = 's';
		}

		//Beep(50000
		return key;		//Return the key pressed.
	}
}

//################################################## FIND HERO POSITION ##############################################################
void Game::findHeroPosition()
{
	for (int y = 0; y < mazeSize; y++)		
	{
		for (int x = 0; x < mazeSize; x++)
		{
			if (myMaze.mazeBoard[y][x] == myMaze.heroID)			//Looks thought all the blocks in the maze untill it finds the hero.
			{
				myMaze.hor = x;		//Returns the x and y position of the hero.
				myMaze.vert = y;
			}
		}
	}
}

//################################################## CHECK HEALTH ##############################################################
bool Game::checkHealth()
{
	if (gameOver)			//If the game is over.
	{
		return true;		//Return true.
	}
		
	if (myMaze.myHero.heath <= 0)		//If the hero's HP is zero or below zero.
	{
		cout << endl << "You lost" << endl;		//Display you lost.
		return true;		//Return true.
	}

	else
	{
		return false;		//Else return false.
	}
}

//################################################## CHECK MONSTER HP ##############################################################
void Game::checkMonsterHealth(Monster* myMonster, int y, int x)
{
	if (myMonster->heath <= 0)			//If the mosnter's HP is zero or below zero.
	{
		myMaze.mazeBoard[y][x] = myMaze.emptyID;		//Then make that block empty.
		system("CLS");
		refresh("");
	}

	else
	{
		return;			//Else just return nothing.
	}
}

//################################################## CHECK LOOP MOVE ##############################################################
bool Game::checkLoopMove(bool backTrack)
{
	if (backTrack)			//If it from the backs stack.
	{
		if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.emptyID)		//If the position the hero is moving to is an empty space.
		{
			return true;
		}

		else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.finishID)		//If the position the hero is moving to is the exit.
		{
			gameOver = true;			//Game over true.
			return true;
		}

		else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.wallID)		//If the position the hero is moving to is a wall.
		{
			refresh("");		//Refresh and dsiplay maze.
			return false;
		}

		else if ((myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.door->getID()))		//If the position the hero is moving to is a door.
		{
			if (myMaze.myHero.checkInventory(myMaze.key))		//Checks if the hero's contains the key.
			{
				return true;		//If yes, he can pass
			}

			else
			{
				refresh("");
				return false;			//Does not let them pass.
			}
		}

		else if ((myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.key->getID()))		//If the position the hero is moving to is a key.
		{
			myMaze.myHero.pickObject(myMaze.key);			//Picks up the key.
			foundKey();			//Calls the found key function.
			return true;
		}
	}

	else
	{
		if ((myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.emptyID) && (myMaze.visted[myMaze.vert][myMaze.hor] == 0))			//If the position the hero is moving to is an empty space and there is not break crumps.
		{
			return true;		
		}

		else if ((myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.emptyID) && (myMaze.visted[myMaze.vert][myMaze.hor] == 1))	//If the position the hero is moving to is an empty space and there is a break crumps.
		{
			return false;
		}

		else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.finishID)		//If the position the hero is moving to is the exit.
		{
			gameOver = true;			//Game over is true.
			return true;
		}

		else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.wallID)		//If the position the hero is moving to is a wall.
		{
			refresh("");
			return false;
		}

		else if ((myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.door->getID()))		//If the position the hero is moving to is a door.
		{
			if (myMaze.myHero.checkInventory(myMaze.key))		//Checks if the hero's contains the key.
			{
				return true;		//If yes, he can pass
			}

			else
			{
				refresh("");
				return false;			//Does not let them pass.
			}
		}

		else if ((myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.key->getID()))		//If the position the hero is moving to is a key.
		{
			myMaze.myHero.pickObject(myMaze.key);			//Picks up the key.
			foundKey();		//Calls the found key function.
			return true;
		}
	}
}

//################################################## FOUND KEY ##############################################################
void Game::foundKey()
{			
	mainStack->emptyStack();		//Empties the main stack.
	backStack->emptyStack();		//Empties the back stack.
	initializeStack();				//Intializes the main stack.
	initializeVisited();			//Intializes the visited array to all false (not visited).
}

//################################################## INITIALIZE VISITED ##############################################################
void Game::initializeVisited()
{
	for (int i = 0; i < 22; i++)
	{
		for (int x = 0; x < 22; x++)
		{
			myMaze.visted[i][x] = 0;		//Sets all theb blocks in the array to not visited.
		}
	}
}

//################################################## CHECK FOR MONSTERS ##############################################################
bool Game::checkForMonsters()
{
			if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.zombie->getID())			//If the position the hero is moving to is a zombie.
			{
				refresh("");
				myMaze.myHero.fight(myMaze.zombie);
				myMaze.displayMonsterHP(myMaze.zombie);
				checkMonsterHealth(myMaze.zombie, myMaze.vert, myMaze.hor);
				return false;
			}

			else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.vampire->getID())		//If the position the hero is moving to is a vampire.
			{	
				refresh("");
				myMaze.myHero.fight(myMaze.vampire);
				myMaze.displayMonsterHP(myMaze.vampire);
				checkMonsterHealth(myMaze.vampire, myMaze.vert, myMaze.hor);
				return false;
			}

			else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.warewolf->getID())		//If the position the hero is moving to is a warewolf.
			{
				refresh("");
				myMaze.myHero.fight(myMaze.warewolf);
				myMaze.displayMonsterHP(myMaze.warewolf);
				checkMonsterHealth(myMaze.warewolf, myMaze.vert, myMaze.hor);
				return false;
			}

			else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.demon->getID())		//If the position the hero is moving to is a demon.
			{
				refresh("");
				myMaze.myHero.fight(myMaze.demon);
				myMaze.displayMonsterHP(myMaze.demon);
				checkMonsterHealth(myMaze.demon, myMaze.vert, myMaze.hor);
				return false;
			}

			else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.bigfoot->getID())		//If the position the hero is moving to is a bigfoot.
			{
				refresh("");
				myMaze.myHero.fight(myMaze.bigfoot);
				myMaze.displayMonsterHP(myMaze.bigfoot);
				checkMonsterHealth(myMaze.bigfoot, myMaze.vert, myMaze.hor);
				return false;
			}

			else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.lucifer->getID())		//If the position the hero is moving to is a lucifer.
			{
				refresh("");
				myMaze.myHero.fight(myMaze.lucifer);
				myMaze.displayMonsterHP(myMaze.lucifer);
				checkMonsterHealth(myMaze.lucifer, myMaze.vert, myMaze.hor);
				return false;
			}
}

//################################################## CHECK MOVE ##############################################################
bool Game::checkMove(bool backTrack)
{
	condition = "";
	system("CLS");

	if (gameType != 4)		//If it is a not a loop mode game.
	{
		if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.emptyID)			//If the position the hero is moving to is an empty space.
		{
			return true;
		}

		else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.finishID)		//If the position the hero is moving to is an exit.
		{
			gameOver = true;
			return true;
		}

		else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.wallID)		//If the position the hero is moving to is a wall.
		{
			if (gameType == 1)		//If it is a manual game mode.
			{
				refresh("                    --> Wall, Cannot move! <--");			//Displays wall connot move.
			}

			else
			{
				refresh("");
			}
			return false;
		}

		else if ((myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.door->getID()))		//If the position the hero is moving to is a door.
		{
			if (myMaze.myHero.checkInventory(myMaze.key))		//Checks if the hero's contains the key.
			{
				return true;		//If yes, he can pass
			}

			else
			{
				refresh("");
				condition = "\n                       --> Door, Find Key! <--";		//Else displays find key.
				return false;			//Does not let them pass.
			}
		}

		else if ((myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.key->getID()))		//If the position the hero is moving to is a key.
		{
			myMaze.myHero.pickObject(myMaze.key);			//Picks up the key.
			condition = "\n                        --> Picked up a Key! <--";		//Dsiplays you picked up a key.		
			return true;
		}

		else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.healthID)		//If the position the hero is moving to is a health pack.
		{	
			condition = "\n           --> Picked up a health pack, health increased <--";			//Dispalys health increased.
			myMaze.mazeBoard[myMaze.vert][myMaze.hor] == 0;			//Makes the position in the array an empty space.
			myMaze.myHero.useItem(myMaze.healthPotion);			//Uses the health pack.
			return true;
		}

		else if (myMaze.mazeBoard[myMaze.vert][myMaze.hor] == myMaze.sword->getID())			//If the position the hero is moving to is a sword.
		{
			condition = "\n                --> Picked up a sword, damage increased <--";		//Dispalys picked a sword.
			myMaze.mazeBoard[myMaze.vert][myMaze.hor] == 0;		//Makes the position in the array an empty space.
			myMaze.myHero.weaponEquipped = true;		//Marks weapon equipped as true.
			myMaze.myHero.weapon = myMaze.sword;		//Equipped the sword.
			myMaze.myHero.useItem(myMaze.sword);		//uses the sword.
			return true;
		}

		return checkForMonsters();		//Return check if monster.
	}

	else if (gameType == 4)		//If it is a loop mode game.
	{
		return checkLoopMove(backTrack);		//Then check loop move.
	}
}

//################################################## CHECK MONSTER MOVE ##############################################################
bool Game::checkMonsterMove(int y, int x)
{
	if (myMaze.mazeBoard[y][x] == myMaze.emptyID)		//If the monster moves to an empty space.
	{
		return true;		//Return true.
	}

	else if (myMaze.mazeBoard[y][x] == myMaze.myHero.getID())		//If the monster moves to a hero.
	{
		return false;			//Return false.
	}

	else
	{
		return false;		//Else return false.
	}
}

//################################################## MOVE MONSTER ##############################################################
void Game::moveMonster(Monster * myMonster, int y, int x)
{
	if (myMonster->moved == true)		//If the monster had moved before.
	{
		return;
	}

	int myMove = rand() % 5;			//Generates a random number.
	
	if (myMove == 0)		//if the move is 0 then do nothing,
	{
		return;
	}

	else if (myMove == 1)		//if the move is 1 then move down.
	{
		if (checkMonsterMove(y + 1, x))
		{
			myMaze.mazeBoard[y + 1][x] = myMonster->getID();		//Swap spots in the maze.
			myMaze.mazeBoard[y][x] = myMaze.emptyID;
		}
	}

	else if (myMove == 2)		//if the move is 2 then move up.
	{
		if (checkMonsterMove(y - 1, x))
		{
			myMaze.mazeBoard[y - 1][x] = myMonster->getID();		//Swap spots in the maze.
			myMaze.mazeBoard[y][x] = myMaze.emptyID;
		}
	}

	else if (myMove == 3)		//if the move is 3 then move left.
	{
		if (checkMonsterMove(y, x - 1))
		{
			myMaze.mazeBoard[y][x - 1] = myMonster->getID();		//Swap spots in the maze.
			myMaze.mazeBoard[y][x] = myMaze.emptyID;
		}
	}

	else if (myMove == 4)		//if the move is 4 then move right.
	{
		if (checkMonsterMove(y, x + 1))
		{
			myMaze.mazeBoard[y][x + 1] = myMonster->getID();		//Swap spots in the maze.
			myMaze.mazeBoard[y][x] = myMaze.emptyID;
		}
	}

	myMonster->moved = true;
}

//################################################## FIND MONSTER ##############################################################
void Game::findMonster()
{
	//Sets all the monster moves to false.
	myMaze.zombie->moved = false;
	myMaze.vampire->moved = false;
	myMaze.zombie_
	myMaze.warewolf->moved = false;
	myMaze.demon->moved = false;
	myMaze.bigfoot->moved = false;
	myMaze.lucifer->moved = false;

	for (int y = 0; y < mazeSize; y++)
	{
		for (int x = 0; x < mazeSize; x++)
		{
			if (myMaze.mazeBoard[y][x] == myMaze.zombie->getID())		//If it is zombie.
			{
				moveMonster(myMaze.zombie, y, x);		//Moves zombie.
			}

			if (myMaze.mazeBoard[y][x] == myMaze.vampire->getID())		//If it is vampire.
			{
				moveMonster(myMaze.vampire, y, x);		//Moves vampire.
			}

			if (myMaze.mazeBoard[y][x] == myMaze.warewolf->getID())		//If it is warewolf.
			{	
				moveMonster(myMaze.warewolf, y, x);		//Moves warewolf.
			}

			if (myMaze.mazeBoard[y][x] == myMaze.demon->getID())		//If it is demon.
			{
				moveMonster(myMaze.demon, y, x);		//Moves demon.
			}

			if (myMaze.mazeBoard[y][x] == myMaze.bigfoot->getID())		//If it is bigfoot.
			{
				moveMonster(myMaze.bigfoot, y, x);		//Moves bigfoot.
			}

			if (myMaze.mazeBoard[y][x] == myMaze.lucifer->getID())		//If it is lucifer.
			{
				moveMonster(myMaze.lucifer, y, x);		//Moves lucifer.
			}	
		}
	}
}

//################################################## INITIALIZE STACK ##############################################################
void Game::initializeStack()
{
	//Intialzes the stack
	mainStack->push(up);
	mainStack->push(left);
	mainStack->push(right);
	mainStack->push(down);
}

//################################################## STACK DIRECTION ##############################################################
char Game::getStackDirection()
{
	//Returns the top direction from the main stack.
	return mainStack->peek();
}

//################################################## ADD DIRECTIONS ##############################################################
void Game::addDirections()
{
	if (direction == up)			//Adds directions to the stack according to the previous move onto the main stack. And then adds the opposite move onto the back stack.
	{
		backStack->push(down);
		mainStack->push(back);
		mainStack->push(left);
		mainStack->push(right);
		mainStack->push(up);
	}

	if (direction == down)
	{
		backStack->push(up);
		mainStack->push(back);
		mainStack->push(left);
		mainStack->push(right);
		mainStack->push(down);
	}

	else if (direction == left)
	{
		backStack->push(right);
		mainStack->push(back);
		mainStack->push(up);
		mainStack->push(down);
		mainStack->push(left);
	}

	else if (direction == right)
	{
		backStack->push(left);
		mainStack->push(back);
		mainStack->push(up);
		mainStack->push(down);
		mainStack->push(right);
	}
}

//################################################## TRY MOVE ##############################################################
bool Game::tryMove(int id, int id2)
{
	bool checkDefault = false;			
	bool backTrack;

	if (id2 == 1)		//If the function is called from the back stack.
	{
		backTrack = true;		//Set the back stack variable to true..
	}

	else
	{
		backTrack = false;		//Else set the back stack varaible to false.
	}

	switch (direction)		//A switch that checks the direction that is going to be moved.
	{
	case 'w':
		myMaze.vert--;
		if (checkMove(backTrack))			//If it a valid move
		{
			totalPaths++;
			myMaze.mazeBoard[myMaze.vert][myMaze.hor] = myMaze.heroID;		//Switches the spots in the array.
			myMaze.mazeBoard[myMaze.vert + 1][myMaze.hor] = 0;
			refresh("");
			cout << condition << endl;			//Displays any conditions.

			if (gameType == 4)			//If game mode is loop testing then use the break crumps. 
			{
				myMaze.visted[myMaze.vert + 1][myMaze.hor] = 1;
			}

			if (gameOver)		//If game over then display game over.
			{
				cout << endl << "You won!" << endl;
			}
			return true;
		}		
		cout << condition << endl;		//Display conditions if any.
		return false;

		//Similar to case 'w' except the move.
	case 's':
		myMaze.vert++;
		if (checkMove(backTrack))
		{
			totalPaths++;
			myMaze.mazeBoard[myMaze.vert][myMaze.hor] = myMaze.heroID;
			myMaze.mazeBoard[myMaze.vert - 1][myMaze.hor] = 0;
			refresh("");
			cout << condition << endl;

			if (gameType == 4)
			{
				myMaze.visted[myMaze.vert - 1][myMaze.hor] = 1;
			}

			if (gameOver)
			{
				cout << endl << "You won!" << endl;
			}
			return true;
		}
		cout << condition << endl;
		return false;

		//Similar to case 'w' except the move.
	case 'a':
		myMaze.hor--;
		if (checkMove(backTrack))
		{
			totalPaths++;
			myMaze.mazeBoard[myMaze.vert][myMaze.hor] = myMaze.heroID;
			myMaze.mazeBoard[myMaze.vert][myMaze.hor + 1] = 0;
			refresh("");
			cout << condition << endl;

			if (gameType == 4)
			{
				myMaze.visted[myMaze.vert][myMaze.hor + 1] = 1;
			}

			if (gameOver)
			{
				cout << endl << "You won!" << endl;
			}
			return true;
		}
		cout << condition << endl;
		return false;

		//Similar to case 'w' except the move.
	case 'd':
		myMaze.hor++;
		if (checkMove(backTrack))
		{
			totalPaths++;
			myMaze.mazeBoard[myMaze.vert][myMaze.hor] = myMaze.heroID;
			myMaze.mazeBoard[myMaze.vert][myMaze.hor - 1] = 0;
			refresh("");
			cout << condition << endl;

			if (gameType == 4)
			{
				myMaze.visted[myMaze.vert][myMaze.hor - 1] = 1;
			}

			if (gameOver)
			{
				cout << endl << "You won!" << endl;
			}
			return true;
		}
		cout << condition << endl;
		return false;

	case 'b':
		move(2, 1);		//Move and state that it is a back stack.
		return false;



	default:
		system("CLS");	
		checkDefault = true;

		if (gameType == 1)
		{
			refresh("                         --> Wrong Key <--");			//Display wrong key.
		}

		else
		{
			refresh("");
		}
		break;
	}
}

//################################################## MOVE ##############################################################
void Game::move(int id, int id2)
{
	findHeroPosition();			//Finds the hero's location
	findMonster();		//Finds the monsters location.
	

	if (id == 1)		//If the autosolver is set to false.
	{
		direction = getKeyPress();		//Get the direction from the arrow keys or "w","a","s" and "d"
		tryMove(id, id2);		//Try to move in the direction.
	}

	
	else if (id == 2)		//If the autosolver is set to true.
	{
		if (id2 == 0)		//If the function is called from the main stack.
		{
			direction = mainStack->pop();		//Get and store the direction from the main stack.
			if (tryMove(id, id2))		//Try to move in that direction.
			{
				addDirections();		//If it is succesful then add directions to the main stack.
			}
		}

		else if (id2 == 1)		//If the function is called from the back stack.
		{
			direction = backStack->pop();		//Get and store the direction from the back stack.
			tryMove(id, id2);		//Try to move in that direction.
			id2 = 0;				//Switch it back to the main stack.
		}
	}
}

//################################################## DESTRUCTOR ##############################################################
Game::~Game()
{
}
