/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/

#include <iostream>
#include "GenListQueue.h"
using namespace std;


int main(int argc, char** argv)
{
	cout << "Hello!" << endl;


	GenListQueue<int> myQueue = GenListQueue<int>();

	myQueue.insert(5);
	myQueue.insert(6);

	cout << myQueue.peak() << endl;

}