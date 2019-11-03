/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/

#include "Student.h"
#include "StatisticsMonitor.h"

class Window
{
public:
	Window();
	~Window();

	//functions
	void timeStep();

	//variables
	bool occupied;
	Student* currentStudent;

	//stats monitoring vars
	unsigned int idleTime;
};