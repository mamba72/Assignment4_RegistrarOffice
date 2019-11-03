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
	cout << "Hello!" << endl;

	Registrar* office;
	//this try is to catch any file reading errors
	try
	{
		office = new Registrar("ExampleTestInput.txt");
	}
	catch (FileNotInCorrectFormatException e)
	{
		//cout << "File not in correct format exception.\n";
		cout << e.what() << endl;
		return 1;
	}
	catch (CouldNotOpenFileException e)
	{
		//cout << "Could not open file exception.\n";
		cout << e.what() << endl;
		return 1;
	}
	


	cout << office->fileLines->peak() << endl;
	//cout << office->studentLine->peak() << endl;

	office->timeStep();

	office->timeStep();
	cout << office->studentLine->peak()->toString() << endl;



	//now actually do some stuff like stepping through time
	//cause you know... im baller like that

	//main while loop
	//do while because the 0th time step is getting all the students

	//do
	//{
	//	office->timeStep();


	//} while (office->stillProcessingStudents());



	return 0;
}