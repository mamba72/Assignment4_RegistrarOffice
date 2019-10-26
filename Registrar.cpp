/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/
#include "Registrar.h"

Registrar::Registrar(int numWindows)
{
	this->numWindows = numWindows;

	windowArray = new Window[numWindows];
}

Registrar::~Registrar()
{

}


void Registrar::UpdateAllStudentTimes()
{

}