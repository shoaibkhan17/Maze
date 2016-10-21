#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#pragma once
class Link
{
public:
	Link();
	~Link();

	//Public varaibles
	Link* prev;		//Pointer that points to the previous link.
	Link* next;		//Pointer that points to the next link.
	char direction;	
};

