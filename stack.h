//*****************************************************************************************************
//
//		File:					stack.h
//
//		Student:				Cadence Seim
//
//		Assignment:				Program #10
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-Z1
//
//		Due:					04/06/2025
//
//
//		This program creates an array based stack with various functions.
//	
//		Other files required: 
//			1. rpn.cpp
//			
//*****************************************************************************************************

#ifndef STACK_H
#define STACK_H

//*****************************************************************************************************

template<typename TYPE>
class Stack
{

private:
	TYPE* start;
	int top;
	int capacity;

public:
	Stack(int size = 80);
	~Stack();
	bool push(const TYPE& dataIn);
	bool pop(TYPE& dataIO);
	bool peek(TYPE& dataIO) const;
	int getNumValues() const;
	bool isFull() const;
	bool isEmpty() const;
};

//*****************************************************************************************************

template <typename TYPE>
Stack<TYPE>::stack(int size)
{
	capacity = size;
	start = new TYPE[capacity];
	top = -1;
}

//*****************************************************************************************************

template <typename TYPE>
Stack<TYPE>:: ~stack()
{
	delete[] start;
	start = nullptr;
	capacity = 0;
	top = -1;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::push(const TYPE& dataIn)
{
	bool success = false;

	if (top + 1 < capacity)
	{
		top++;
		start[top] = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::pop(TYPE& dataIO)
{
	bool success = false;

	if (top >= 0)
	{
		dataIO = start[top];
		top--;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::peek(TYPE& dataIO) const
{
	bool success = false;

	if (top >= 0)
	{
		dataIO = start[top];
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
int Stack<TYPE>::getNumValues() const
{
	return top + 2;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::isFull() const
{
	return (top + 1 == capacity);
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::isEmpty() const
{
	return (top == -1);
}

//*****************************************************************************************************
#endif 