//stack.h
#ifndef STACK
#define STACK

#include<iostream>
using namespace std;

typedef int ItemType;

class Stack{

	public:
	
		Stack();
		//Stack constructor
		~Stack();
		//Destructor
		
		//Stack(const Stack &object);
		
		//Stack &operator=(const Stack &object);

		int size() const;
		//Returns stack size
		bool empty() const;
		//Returns true if stack is empty, else returns false
		void push(ItemType item);
		//Gets an item as an input
		//Pushes an item into the stack, increases stackSize
		void pop();
		//Pops an item out of the stack, decreases stackSize
		ItemType top() const;
		//Returns the most recently added element in the stack
		
	private:

		class Node{
			public:
				ItemType data;
				Node *next;
		};

		Node* head;
		int stackSize;
};
#endif
