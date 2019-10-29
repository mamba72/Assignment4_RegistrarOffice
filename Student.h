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
	Student(unsigned int time);
	~Student();

	void timeStep();

	bool isAtWindow;
	unsigned int originalWindowTime;
	unsigned int windowTimeLeft;
	unsigned int waitTime;
};

