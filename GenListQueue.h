/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/
#pragma once
#include "GenLinkedList.h"

template <class T>
class GenListQueue
{
public:
	GenListQueue();//default constructor
	//GenListQueue(int maxSize); //overloaded constructor
	~GenListQueue();//destructor

	//core functions
	void insert(T d);
	T remove();

	//aux functions
	T peak();
	//bool isFull();
	bool isEmpty();
	int getSize();

	//NOTE: we dont need these variables because we dont need to make a 
	//circular queue and the list itself maintains the size information

	//variables
	//int size;
	//int front; //aka head
	//int rear; //aka tail
	//int numElements;

	GenLinkedList<T>* myList; //the actual list

};

//this is a struct for throwing a custom exception when the Queue is empty
struct QueueEmptyException : public std::exception
{
	const char* what() const throw ()
	{
		return "This Queue is empty, cannot remove, peek, or pop.";
	}
};

template<class T>
inline GenListQueue<T>::GenListQueue()
{
	myList = new GenLinkedList<T>();
}

template<class T>
inline GenListQueue<T>::~GenListQueue()
{
	delete myList;
}

//insert a given character into the back of the queue
template<class T>
void GenListQueue<T>::insert(T d)
{
	myList->insertBack(d);
}

//returns and removes the first element in the list
template<class T>
T GenListQueue<T>::remove()
{
	//if the list is empty, it will throw a list empty exception.
	//but since this wont appear as a list to the user, "convert"
	//it to a QueueEmptyException instead (just to make it less
	// confusing to the user
	try
	{
		return myList->removeFront();
	}
	catch (ListEmptyException e)
	{
		throw QueueEmptyException();
	}
	
}

//returns the value of the first element in the list
template<class T>
T GenListQueue<T>::peak()
{
	return myList->getPos(0);
}

template<class T>
bool GenListQueue<T>::isEmpty()
{
	return myList->isEmpty();
}

template<class T>
int GenListQueue<T>::getSize()
{
	return myList->getSize();
}

