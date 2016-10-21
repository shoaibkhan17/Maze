#include <iostream>
#include <cstdlib>
#include "link.h"

using namespace std;

#pragma once
class Stack
{
public:
	Stack();
	~Stack();

	//Public functions
	void push(char);			//Adds a direction to the stack
	void displayStack();		//Displays the stack
	void emptyStack();			//Pops/empties the entire stack.
	char pop();					//returns the direction.
	char peek();				//looks at top direction without removing/returning it.

	//Public variables
	Link* top;				//Points to the last link or top of the stack
	int size;
};

