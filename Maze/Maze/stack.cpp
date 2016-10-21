#include "stack.h"

//################################################## CONSTRUCTOR ##############################################################
Stack::Stack()
{
}

//################################################## PUSH ##############################################################
void Stack::push(char newDirection)
{
	Link *newLink;		//Creates a pointer to a new link.
	newLink = new Link;		
	newLink->direction = newDirection;		//Makes the new links direction to the direction provided.
	newLink->prev = top;		//Adds that link to the current list. 
	top = newLink;
	size++;		//Increases the size that states the size of the list.
}

//################################################## PEEK ##############################################################
char Stack::peek()
{
	return top->direction;		//return the top most direction.
}

//################################################## POP ##############################################################
char Stack::pop()
{

	if (top != NULL)
	{
		char returnChar;		//Defines a character.
		returnChar = top->direction;		//Assignes it the direction of the top most direction.
		top = top->prev;		//Makes the top of the list the previous list.
		size--;					//Decreses the size that states the size of the list.
		return returnChar;		//Returns the direction. 
	}
}

//################################################## DISPLAY STACK ##############################################################
void Stack::displayStack()
{	
	Link * temp = top;

	while (temp != NULL)
	{
		cout << temp->direction;
		temp = temp->prev;
		cout << endl;
	}

}


void Stack::emptyStack()
{
	while (top->prev != NULL)	
	{
		pop();		//Goes throught every single link in the stack and then pops them out.
	}
}

//################################################## DESTRUCTOR ##############################################################
Stack::~Stack()
{
}
