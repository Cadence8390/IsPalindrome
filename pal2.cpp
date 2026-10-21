//*****************************************************************************************************
//
//		File:					pal2.cpp
//
//		Student:				Cadence Seim
//
//		Assignment:				Program #9
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-Z1
//
//		Due:					4/17/2025
//
//
//		This program uses a stack and a queue to determine if a c-string is a plaindrome.
//	
//		Other files required: 
//			1. stack.h
//			2. queue.h
//			3. palindromes.txt
//			
//*****************************************************************************************************

#include<iostream>
#include<fstream>

using namespace std;

#include "stack.h"
#include "node.h"
#include "queue.h" 

//*****************************************************************************************************

bool testNdisplay(Stack<char>& s1, Queue<char>& q1);
char getPalType(bool isPunct, bool isSpace);
void displayPalResult(bool isValid, char palType);

//*****************************************************************************************************

int main()
{
	Stack<char> s1;
	Queue<char> q1;
	bool isValid,
		hasPunct,
		hasSpace;
	char palType;
	char pal[80];
	int len;

	char test;

	ifstream palFile("palindromes.txt");

	while (palFile.getline(pal, 80, '#'))
	{
		hasPunct = false;
		hasSpace = false;
		isValid = true;
		len = int(strlen(pal));

		for (int x = 0; x < len; x++)
		{
			if (isalpha(pal[x]))
			{
				pal[x] = tolower(pal[x]);
				s1.push(pal[x]);
				q1.enqueue(pal[x]);
			}
			else if (ispunct(pal[x]))
			{
				hasPunct = true;
			}
			else if (isspace(pal[x]))
			{
				hasSpace = true;
			}
		}

		isValid = testNdisplay(s1, q1);

		palType = getPalType(hasPunct, hasSpace);

		cout << "\t" << "\t";
		displayPalResult(isValid, palType);
		cout << endl;

	}

	return 0;
}


//*****************************************************************************************************

bool testNdisplay(Stack<char>& s1, Queue<char>& q1)
{
	bool isPal = true;
	char temp1;
	char temp3;

	while (s1.pop(temp1) && q1.dequeue(temp3))
	{
		if (temp1 != temp3)
		{
			isPal = false;
		}

		cout << temp1;
	}

	return isPal;
}

//*****************************************************************************************************

char getPalType(bool hasPunct, bool hasSpace)
{
	char palType = '1';

	if (hasPunct)
	{
		palType = '3';
	}
	else if (hasSpace)
	{
		palType = '2';
	}

	return palType;

}

//*****************************************************************************************************

void displayPalResult(bool isValid, char palType)
{
	if (isValid)
	{
		cout << "Type: " << palType;
	}
	else
	{
		cout << "Invalid";
	}
}

//*****************************************************************************************************

/*

aha             Type: 3
isitiitisi              Type: 3
deed            Type: 1
srotor          Invalid
neveroddoreven          Type: 2
nolemonsnomelon         Type: 3
racecar         Type: 2
cimoc           Invalid
wasitacaroracatisaw             Type: 3
yddad           Invalid

*/