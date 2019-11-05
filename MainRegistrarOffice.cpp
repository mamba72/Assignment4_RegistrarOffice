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
	


	//cout << office->fileLines->peak() << endl;
	//cout << office->studentLine->peak() << endl;

	//office->timeStep();

	//office->timeStep();
	//cout << office->studentLine->peak()->toString() << endl;
	//cout << "Length of the line: " << office->studentLine->getSize() << endl;


	//for (int i = 0; i < 8; ++i)
	while(office->stillProcessingStudents())
	{
		//cout << "I: " << i << endl;
		office->timeStep();
		//try
		//{
		//	cout << office->studentLine->peak()->toString() << endl;
		//}
		//catch (QueueEmptyException e)
		//{
		//	//cout << "Queue Empty, continuing.\n";
		//	//do nothing.
		//}
		
		cout << "Length of the line: " << office->studentLine->getSize() << endl;

		int occupiedWindows = 0;
		for (int i = 0; i < office->numWindows; ++i)
		{
			if (office->windowArray[i].occupied == true)
				occupiedWindows++;
		}
		cout << "Number of occupied windows: " << occupiedWindows << endl;

		cout << "Window info:\n";
		for (int i = 0; i < office->numWindows; ++i)
		{
			cout << "\t" << office->windowArray[i].toString() << endl;
		}

		cout << endl;
	}

	cout << "Length of completed students list: " <<  office->completedStudents->getSize() << endl;

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