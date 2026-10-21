//*****************************************************************************************************
//
//		File:					node.h
//
//		Student:				Cadence Seim
//
//		Assignment:				Program #5
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-Z1
//
//		Due:					4/17/2025
//
//
//		This is the system program for a node.
//	
//		Other files required:
//		
//			
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename TYPE>
struct Node
{
public:
	TYPE data;
	Node<TYPE>* next;
	Node();
	Node(const TYPE& dat, Node<TYPE>* nex = nullptr);
};

//*****************************************************************************************************

template<typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
}

//*****************************************************************************************************

template<typename TYPE>
Node<TYPE>::Node(const TYPE& dat, Node<TYPE>* nex)
{
	data = dat;
	next = nex;
}

//*****************************************************************************************************

#endif;
