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
}

Window::~Window()
{

}

//step through the time
void Window::timeStep()
{
	if (occupied == true)
	{
		currentStudent->timeStep();
	}
	else
	{
		idleTime++;
	}
}