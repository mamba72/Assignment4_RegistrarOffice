/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/
#pragma once
#include "Student.h"
#include "StatisticsMonitor.h"
#include <string>
//#include "Registrar.h"

class Window
{
public:
	Window();	
	~Window();

	//functions
	void timeStep();
	void takeInStudent(Student* student, unsigned int currTime);

	bool isDoneWithStudent();
	Student* removeStudent();
	string toString();

	//variables
	bool occupied;


	//stats monitoring vars
	unsigned int idleTime;

	unsigned int currentTime;
	unsigned int timeWithCurrentStudent;

	//StatisticsMonitor* statsMonitor;

private:
	Student* currentStudent;
};