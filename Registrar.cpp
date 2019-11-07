/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/
#include "Registrar.h"
#include <algorithm>
using namespace std;

Registrar::Registrar(string fileName)
{
	currentTime = 0;
	readFile(fileName);
	studentLine = new GenListQueue<Student*>();
	completedStudents = new GenLinkedList<Student*>();
	//statsMonitor = new StatisticsMonitor();

	//assign the first number in the file to the number of windows
	numWindows = fileLines->remove();
	//create the window array
	windowArray = new Window[numWindows];
}

Registrar::~Registrar()
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
		try
		{
			int num = stoi(line);

			//make sure all the numbers are greater than 0
			if (num < 1)
				throw FileNotInCorrectFormatException("File cannot contain numbers less than 1");
			
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

	try
	{
		if (currentTime != fileLines->peak())
			return false;
	}
	catch (QueueEmptyException e)
	{
		throw FileNotInCorrectFormatException("The time the next batch of students arrives could not be determined.\nEnsure your file is in the correct format.");
	}
	
	int time;
	try
	{
		time = fileLines->remove();//remove the time number from the queue
	}
	catch (QueueEmptyException e)
	{
		throw FileNotInCorrectFormatException("The time the next batch of students arrives could not be determined.\nEnsure your file is in the correct format.");
	}
	
	int numNextStudents;
	try
	{
		numNextStudents = fileLines->remove();
	}
	catch (QueueEmptyException e)
	{
		throw FileNotInCorrectFormatException("The amount of students does not match the times provided.");
	}
	
	try
	{
		for (int i = 0; i < numNextStudents; ++i)
		{
			unsigned int studentWindowTime = fileLines->remove();
			Student* nextStudent = new Student(studentWindowTime, currentTime);
			studentLine->insert(nextStudent);
		}
	}
	catch (QueueEmptyException e)
	{
		throw FileNotInCorrectFormatException("The amount of students does not match the times provided.");
	}

	

	return true;
}

//will return true of there are more lines to read from the file
bool Registrar::hasMoreStudents()
{
	//return the opposite of isEmpty
	return !fileLines->isEmpty();
}

//if any of the windows are idle, try to fill them with a student
void Registrar::fillWindows()
{
	//if the line is empty, dont try to remove students from it.
	if (studentLine->isEmpty())
		return;

	//iterate through the windows, if the window is open, put a student in it
	for (int i = 0; i < numWindows; ++i)
	{
		//if the wondow is free...
		if (windowArray[i].occupied == false)
		{
			try
			{
				windowArray[i].takeInStudent(studentLine->remove(), currentTime);
			}
			catch (QueueEmptyException e)
			{
				break;
			}
		}
	}
}

//this will return whether the registrar is completely done or not
bool Registrar::stillProcessingStudents()
{
	//if there are still students in the file
	if (hasMoreStudents())
		return true;
	
	//check if any windows are still occupied
	for (int i = 0; i < numWindows; ++i)
	{
		if (windowArray[i].occupied == true)
			return true;
	}

	//if there are any students in the line
	if (studentLine->isEmpty() == false)
		return true;

	return false;
}

//actually step through one time unit
void Registrar::timeStep()
{
	//iterate through the windows time stepping them
	for (int i = 0; i < numWindows; ++i)
	{
		windowArray[i].timeStep();
	}
	//remove the current students from the windows if they need to be removed, and add them to completed list
	for (int i = 0; i < numWindows; ++i)
	{
		if (windowArray[i].isDoneWithStudent())
		{
			Student* completedStudent = windowArray[i].removeStudent();
			completedStudents->insertFront(completedStudent);
		}
	}

	//the students will enter the line
	getNextStudents();

	//now ensure that all the windows are occupied
	fillWindows();

	//increment the current time
	currentTime++;
}

//calculate and print out the required stats
void Registrar::calcStats()
{

	//student focused stats
	unsigned int totalStudentQueueWaitTime = 0;
	float meanWaitTime;
	unsigned int medianWaitTime = 0;
	unsigned int longestWaitTime = 0;
	unsigned int numWaitingOverTenMin = 0;

	unsigned int numStudents = completedStudents->getSize();

	unsigned int* queueWaitTimeArray = new unsigned int[numStudents];
	//get the total student wait times
	//does not end up ruining the list (inserts the student back into the list so we can do more stats)
	for(int i = 0; i < numStudents; ++i)
	{
		Student* currStudent = completedStudents->removeFront();

		unsigned int studentsWaitTime = currStudent->timeEnteredWindow - currStudent->timeEnteredLine;
		totalStudentQueueWaitTime += studentsWaitTime;

		queueWaitTimeArray[i] = studentsWaitTime;

		//get the longest wait time
		if (studentsWaitTime > longestWaitTime)
			longestWaitTime = studentsWaitTime;

		//count the number of students waiting over 10 min
		if (studentsWaitTime > 10)
			numWaitingOverTenMin++;


		completedStudents->insertBack(currStudent);
	}

	meanWaitTime = totalStudentQueueWaitTime / numStudents;

	//window focused stats
	float meanIdleTime;
	unsigned int longestIdleTime = 0;
	unsigned int numIdleOverFiveMin = 0; //make sure this is at first

	unsigned int totalWindowIdleTime = 0;

	for (int i = 0; i < numWindows; ++i)
	{
		totalWindowIdleTime += windowArray[i].idleTime;

		//assign the longest idle time
		if (longestIdleTime < windowArray[i].idleTime)
			longestIdleTime = windowArray[i].idleTime;

		if (windowArray[i].idleTime > 5)
			numIdleOverFiveMin++;

	}

	meanIdleTime = totalWindowIdleTime / numWindows;

	//calculate the median student wait time
	sort(queueWaitTimeArray, queueWaitTimeArray + completedStudents->getSize());

	int medianIndex = completedStudents->getSize() / 2;

	medianWaitTime = queueWaitTimeArray[medianIndex];

	//cout << "Total student wait time: " << totalStudentQueueWaitTime << endl;
	cout << "1. Mean Student wait time: " << meanWaitTime<< endl;
	cout << "2. Median Student Wait Time: " << medianWaitTime << endl;
	cout << "3. Longest Student Wait Time: " << longestWaitTime << endl;
	cout << "4. Number of Students Waiting Over 10 Minutes: " << numWaitingOverTenMin << endl;
	cout << "5. Mean Window Idle Time: " << meanIdleTime << endl;
	cout << "6. Longest Window Idle Time: " << longestIdleTime << endl;
	cout << "7. Number of windows idle for over 5 minutes: " << numIdleOverFiveMin << endl;
}