#include "Maze.h"

//################################################## CONSTRUCTOR ##############################################################
Maze::Maze()
{
	//Initilizes the pointers.
	zombie = new Monster("Zombie", "!_!", 10, 10, 1, 5);
	vampire = new Monster("Vampire", "@_@", 7, 7, 2, 6);
	warewolf = new Monster("Warewolf","&_&", 4, 4, 4, 7);
	demon = new Monster("Demon","#_#", 6, 6, 2, 8);
	bigfoot = new Monster("Bigfoot", "%_%", 12, 12, 2, 9);
	lucifer = new Monster("Lucifer", "x_x", 15, 15, 1, 10);
	sword = new Item("Sword", swordID, 2, 0, 3);
	healthPotion = new Item("Health Potion", healthID, 0, 6, 1);
	door = new Item("Door", doorID, 0, 0, 1);
	key = new Item("Key", keyID, 0, 0, 1);

	//Sets the varaibles to default values.
	myHero.heath = 20;
	myHero.damage = 4;
}

//################################################## DISPLAY HUD ##############################################################
void Maze::displayHUD()
{
	Utility::changeColour(Utility::healthTitle);		//Changes colour see utility class for more details. 
	string spacing = "        ";			
	int length = 20 - myHero.heath;			//Length is the max hero's HP minus the current hero's HP.

	cout << spacing;
	cout << "Health - ";
	cout << "[";
	Utility::changeColour(Utility::healthColour);
	for (int i = 0; i < myHero.heath; i++)			//Display the HP bar.
	{
		cout << "  ";
	}
	Utility::changeColour(7);
	for (int i = 0; i < length; i++)
	{
		cout << "  ";
	}
	Utility::changeColour(Utility::healthTitle);
	cout << "]";
	Utility::changeColour(7);		//Default colour.
}

//################################################## DISPLAY MONSTER HP ##############################################################
void Maze::displayMonsterHP(Monster * myMonster)
{
	cout << endl;
	Utility::changeColour(Utility::monsterHPTitle);
	string spacing = "        ";
	int length = myMonster->maxHP - myMonster->heath;		//Length is the max monster's HP minus the current monster's HP.


	cout << spacing;
	cout << myMonster->name << " HP - ";
	cout << "[";
	Utility::changeColour(Utility::monsterHPColour);	
	for (int i = 0; i < myMonster->heath; i++)		//Displays the HP bar.
	{
		cout << "  ";				
	}
	Utility::changeColour(7);
	for (int i = 0; i < length; i++)
	{
		cout << "  ";
	}
	Utility::changeColour(Utility::monsterHPTitle);
	cout << "]";
	Utility::changeColour(7);		//Default colour.
}

//################################################## TRANSFER ARRAY ##############################################################
void Maze::transferArray(int mazeArray[22][22])
{
	for (int y = 0; y < 22; y++)
	{
		for (int x = 0; x < 22; x++)
		{
			mazeBoard[y][x] = mazeArray[y][x];			//Transfers the array block by block.
		}
	}
}

//################################################## SET SIZE ##############################################################
void Maze::setSize(int size)
{
	mazeSize = size;			//Sets the maze size.
}	

//################################################## DISPLAY MAZE ##############################################################
void Maze::displayMaze()
{
	for (int y = 0; y < mazeSize; y++)
	{
		for (int x = 0; x < mazeSize; x++)
		{
			cout << displayPieces(y, x);		//Displays the pieces provided from the displayPieces function.
			Utility::changeColour(7);
		}

		cout << endl;
	}
}

//################################################## DISPLAY PIECES ##############################################################
string Maze::displayPieces(int y, int x)
{
	string letter;

	if (mazeBoard[y][x] == emptyID)		//If it is an empty space
	{
		letter = "   ";
	}

	else if (mazeBoard[y][x] == zombie->getID())		//If it an zombie.
	{
		Utility::changeColour(myMonster.myColour);
		letter = zombie->symbol;
	}

	else if (mazeBoard[y][x] == vampire->getID())		//If it a vampire.
	{
		Utility::changeColour(myMonster.myColour);
		letter = vampire->symbol;
	}

	else if (mazeBoard[y][x] == warewolf->getID())		//If it a warewolf.
	{
		Utility::changeColour(myMonster.myColour);
		letter = warewolf->symbol;
	}

	else if (mazeBoard[y][x] == demon->getID())		//If it a demon.
	{
		Utility::changeColour(myMonster.myColour);
		letter = demon->symbol;
	}

	else if (mazeBoard[y][x] == bigfoot->getID())		//If it a bigfoot.
	{
		Utility::changeColour(myMonster.myColour);
		letter = bigfoot->symbol;
	}

	else if (mazeBoard[y][x] == lucifer->getID())		//If it a lucifer.
	{
		Utility::changeColour(myMonster.myColour);
		letter = lucifer->symbol;
	}

	else if (mazeBoard[y][x] == heroID)		//If it a hero.
	{
		Utility::changeColour(myHero.myColour);
		letter = myHero.symbol;
	}

	else if (mazeBoard[y][x] == healthID)		//If it a health pack.
	{
		Utility::changeColour(Utility::healthPotion);
		letter = "|+|";
	}

	else if (mazeBoard[y][x] == startID)		//If it the start.
	{
		Utility::changeColour(Utility::start_end_colour);
		letter = " S ";
	}

	else if (mazeBoard[y][x] == finishID)		//If it the exit.
	{
		Utility::changeColour(Utility::start_end_colour);
		letter = " E ";
	}

	else if (mazeBoard[y][x] == sword->getID())		//If it a sword.
	{
		Utility::changeColour(Utility::swordColour);
		letter = "=--";
	}

	else if (mazeBoard[y][x] == doorID)		//If it a door.
	{
		Utility::changeColour(Utility::doorColour);
		letter = "";
		letter += char(178);
		letter += char(176);
		letter += char(178);
	}

	else if (mazeBoard[y][x] == keyID)		//If it a key.
	{
		Utility::changeColour(Utility::keyColour);
		letter = "o-";
		letter += char(183);

	}

	else				//If it a wall.
	{
		Utility::changeColour(Utility::wallColour);
		letter = " o ";
	}

	return letter;		//returns the assinged letter.
}

//################################################## DESTRUCTOR ##############################################################
Maze::~Maze()
{
}
