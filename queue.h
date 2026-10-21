//*****************************************************************************************************
//
//		File:					queue.cpp
//
//		Student:				Cadence Seim
//
//		Assignment:				Program #9
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-Z1
//
//		Due:					4/17/2025
//
//
//		This is the sysetem program for a queue.
//	
//		Other files required: 
//			1. node.h
//			
//*****************************************************************************************************

#ifndef QUEUE_H
#define QUEUE_H

#include <new>
#include "node.h" 

//*****************************************************************************************************

template<typename TYPE>
class Queue
{
private:
	Node<TYPE>* front;
	Node<TYPE>* rear;
	int numValues;

public:
	Queue();
	~Queue();
	bool enqueue(const TYPE& dataIn);
	bool dequeue(TYPE& dataOut);
	bool viewFront(TYPE& dataOut) const;
	bool viewRear(TYPE& dataOut) const;
	int getNumValues() const;
	bool isFull() const;
	bool isEmpty() const;
};


//*****************************************************************************************************

template<typename TYPE>
Queue<TYPE>::Queue()
{
	front = nullptr;
	rear = nullptr;
	numValues = 0;
}

//*****************************************************************************************************

template<typename TYPE>
Queue<TYPE>:: ~Queue()
{
	Node<TYPE>* pTemp;

	while (front)
	{
		pTemp = front;
		front = front->next;
		delete pTemp;
	}

	numValues = 0;
	rear = nullptr;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::enqueue(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pNew;

	pNew = new (nothrow) Node<TYPE>(dataIn, nullptr);

	if (pNew)
	{
		if (rear)
		{
			rear->next = pNew;
		}
		else
		{
			front = pNew;
		}

		rear = pNew;
		numValues++;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::dequeue(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pDel = front;

	if (front)
	{
		dataOut = front->data;
		front = front->next;
		numValues--;
		delete pDel;
		success = true;
	}

	if (numValues == 0)
	{
		rear = nullptr;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::viewFront(TYPE& dataOut) const
{
	bool success = false;

	if (front)
	{
		dataOut = front->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::viewRear(TYPE& dataOut) const
{
	bool success = false;

	if (rear)
	{
		dataOut = rear->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
int Queue<TYPE>::getNumValues() const
{
	return numValues;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::isFull() const
{
	bool success = true;
	Node<TYPE>* pNew;

	pNew = new (nothrow) Node<TYPE>;

	if (pNew)
	{
		success = false;
		delete pNew;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::isEmpty() const
{
	return (!front);
}

//*****************************************************************************************************

#endif
