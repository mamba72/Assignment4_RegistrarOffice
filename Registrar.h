/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/

#include <iostream>
#include "GenLinkedList.h"
#include "Student.h"
#include "Window.h"
#include "GenListQueue.h"
using namespace std;

class Registrar
{
public:
	Registrar(int numWindows);
	~Registrar();

	//functions
	void UpdateAllStudentTimes();
	void fillWindows();


	//variables
	unsigned short numWindows;
	//the queue of students waiting
	GenListQueue<Student*>* studentLine;
	//the array of windows available
	Window* windowArray;
	//the list of all students done with the registrar
	GenLinkedList<Student*>* completedStudents;


};