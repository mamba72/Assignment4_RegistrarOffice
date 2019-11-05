/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/
#pragma once
#include <iostream>
#include "GenLinkedList.h"
#include "Student.h"
#include "Window.h"
#include "GenListQueue.h"
#include "StatisticsMonitor.h"
#include "fstream"
#include <string>
#include <exception>
using namespace std;

class Registrar
{
public:
	Registrar(string fileName);
	~Registrar();

	//functions
	void updateAllStudentTimes();
	void fillWindows();
	void readFile(string fileName);
	bool getNextStudents();
	bool hasMoreStudents();
	bool stillProcessingStudents();

	void timeStep();

	//variables
	unsigned int numFileLines;
	GenListQueue<int>* fileLines;//the queue of all the numbers from the file
	//the queue of students waiting
	GenListQueue<Student*>* studentLine;
	//the array of windows available
	unsigned short numWindows;
	Window* windowArray;
	//the list of all students done with the registrar
	GenLinkedList<Student*>* completedStudents;

	//the object that maintains all the statistics
	StatisticsMonitor* statsMonitor;

	unsigned int currentTime;
};

//exception to tell whether the file could be opened
class CouldNotOpenFileException : public std::runtime_error
{
	//const char* msg;
public:
	CouldNotOpenFileException(const char* msg) : std::runtime_error(msg)
	{
		//this->msg = msg;
	}

	CouldNotOpenFileException(string msg) : std::runtime_error(msg.c_str())
	{
		//convert the string to a const char*
		//this->msg = msg.c_str();
	}
};

//exception to tell whether the file is in the correct format
//usually thrown if the first line doesnt contain a number
class FileNotInCorrectFormatException : public std::runtime_error
{
	//const char* msg;
public:
	FileNotInCorrectFormatException(const char* msg) : std::runtime_error(msg)
	{
		//this->msg = msg;
	}

	FileNotInCorrectFormatException(string msg) : std::runtime_error(msg.c_str())
	{
		//this->msg = msg;
	}
};

//this exception is when the number of windows is less than 1.
struct InvalidNumWindows : public std::exception
{
	const char* what() const throw ()
	{
		return "The number of windows cannot be less than 1.";
	}
};