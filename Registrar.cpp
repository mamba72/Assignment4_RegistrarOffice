/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/
#include "Registrar.h"

Registrar::Registrar(string fileName)
{
	readFile(fileName);

	//assign the first number in the file to the number of windows
	numWindows = fileLines->remove();
	//create the window array
	windowArray = new Window[numWindows];
}

Registrar::~Registrar()
{

}


void Registrar::updateAllStudentTimes()
{

}

//this function will read in every line of the file into an array
//for quick and easy access to the information at any time.
void Registrar::readFile(string fileName)
{
	fileLines = new GenListQueue<int>();

	ifstream file;
	file.open(fileName);

	if (file.is_open() == false)
		throw CouldNotOpenFileException("The file named " + fileName + " could not be opened.");

	string line = "";
	int lineCounter = 1;
	//go through the file, adding each line to the list
	while (getline(file, line))
	{
		//lineList.insertBack(line);
		try
		{
			int num = stoi(line);
			fileLines->insert(num);
		}
		catch (invalid_argument e)
		{
			string exceptionStr = "File named " + fileName + " is not only integers. Failed on line " + to_string(lineCounter) + ".";
			throw FileNotInCorrectFormatException(exceptionStr.data());
		}
		
		lineCounter++;
	}

	file.close();
}


//this function will get the next few students from the file for the next time interval
//this will add the next students to the current queue of waiting students
bool Registrar::getNextStudents()
{
	//if there are no more students left
	if (hasMoreStudents() == false)
		return false;

	int numNextStudents = fileLines->remove();
	for (int i = 0; i < numNextStudents; ++i)
	{
		unsigned int studentWindowTime = fileLines->remove();
		Student* nextStudent = new Student(studentWindowTime);
		studentLine->insert(nextStudent);
	}

	return true;
}

//will return true of there are more lines to read from the file
bool Registrar::hasMoreStudents()
{
	//return the opposite of isEmpty
	return !fileLines->isEmpty();
}