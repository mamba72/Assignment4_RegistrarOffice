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

	void timeStep();
	string toString();

	bool isAtWindow;
	//unsigned int originalWindowTime;
	//unsigned int windowTimeLeft;
	//unsigned int waitTime;

	unsigned int timeEnteredLine;
	unsigned int timeEnteredWindow;
	unsigned int timeNeededAtWindow;
};

