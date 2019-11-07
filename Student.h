/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/

#pragma once
#include <iostream>

using namespace std;

class Student
{
public:
	Student(unsigned int timeNeeded, unsigned int currentTime);
	~Student();
	//functions
	string toString();

	//vars
	bool isAtWindow;

	unsigned int timeEnteredLine;
	unsigned int timeEnteredWindow;
	unsigned int timeNeededAtWindow;
	unsigned int timeLeftWindow;

};

