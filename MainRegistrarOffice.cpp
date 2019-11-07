/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/

#include <iostream>
#include "GenListQueue.h"
#include "Registrar.h"
using namespace std;


int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << "That was not the correct amount of arguments.\nMake sure you're just inputting the file name that you want to read from.\n";
		return 1;
	}

	Registrar* office;
	//this try is to catch any file reading errors
	try
	{
		office = new Registrar(argv[1]);
	}
	catch (FileNotInCorrectFormatException e)
	{
		cout << e.what() << endl;
		return 1;
	}
	catch (CouldNotOpenFileException e)
	{
		cout << e.what() << endl;
		return 1;
	}

	//now actually do some stuff like stepping through time
	//cause you know... im baller like that
	while (office->stillProcessingStudents())
	{
		office->timeStep();
	}

	office->calcStats();

	return 0;
}