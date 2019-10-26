/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/

#include "Student.h"

Student::Student(int time)
{
	isAtWindow = false;
	windowTimeLeft = time;
	waitTime = 0;
}

Student::~Student()
{
	
}

void Student::timeStep()
{
	if (isAtWindow == true)
		windowTimeLeft--;
	else
		waitTime++;
}