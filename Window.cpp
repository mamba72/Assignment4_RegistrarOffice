/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/

#include "Window.h"

//only used for creating an array
Window::Window()
{
	occupied = false;
	idleTime = 0;
	currentTime = 0;
	timeWithCurrentStudent = 0;
}

Window::~Window()
{

}

//step through the time
void Window::timeStep()
{
	if (occupied == true)
	{
		timeWithCurrentStudent++;
		//currentStudent->timeStep();
	}
	else
	{
		idleTime++;
	}

	currentTime++;
}

//take in a student and ensure the student knows that
void Window::takeInStudent(Student* student, unsigned int currTime)
{
	occupied = true;
	currentStudent = student;
	currentStudent->isAtWindow = true;
	currentStudent->timeEnteredWindow = currTime;
}

//will return whether the student has compeleted its time at the window
//will return false if no student or if student isnt done yet
bool Window::isDoneWithStudent()
{
	if (occupied == false)
		return false;

	//if the student Needs to be removed, return true
	if (currentStudent->timeNeededAtWindow == timeWithCurrentStudent)
		return true;

	return false;
}

//this will reset all the values and remove the student from the window
Student* Window::removeStudent()
{
	//cout << "\t\tRemoving Student\n";

	Student* temp = currentStudent;

	currentStudent->timeLeftWindow = currentTime;

	currentStudent = NULL;
	timeWithCurrentStudent = 0;
	occupied = false;
	return temp;
}

string Window::toString()
{
	string outputStr = "Occupied: " + to_string(occupied);

	if (occupied)
	{
		outputStr = outputStr + " Current Student: " + currentStudent->toString();
		outputStr = outputStr + " Time Spent at Window: " + to_string(timeWithCurrentStudent);
	}
		
	return outputStr;
}