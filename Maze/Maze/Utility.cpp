#include "Utility.h"

//################################################## CONSTRUCTOR ##############################################################
Utility::Utility()
{
}

//################################################## CHANGE COLOUR ##############################################################
void Utility::changeColour(int colourNum)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colourNum);			//Changes the colour to the required colour using the colour code provided.
}

//################################################## DESTRUCTOR ##############################################################
Utility::~Utility()
{
}
