/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/

#include "Student.h"
#include <string>

Student::Student(unsigned int timeNeeded, unsigned int currentTime)
{
	isAtWindow = false;
	//windowTimeLeft = time;
	//waitTime = 0;

	timeNeededAtWindow = timeNeeded;
	timeEnteredLine = currentTime;
	
}

Student::~Student()
{
	
}

//for easy printing
string Student::toString()
{
	string outputStr = "Time Entered: " + to_string(timeEnteredLine) + "\tTime needed at window: " + to_string(timeNeededAtWindow);
	return outputStr;
}