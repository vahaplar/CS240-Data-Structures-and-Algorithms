//queue.h
#ifndef QUEUE
#define QUEUE

#include <iostream>

using namespace std;

typedef string ElementType;

class Queue{
	
	public:
		
		Queue();
		//Queue constructor
		~Queue();
		//Destructor
		int size();
		//Returns the size of queue
		bool empty();
		//Returns true if queue is empty, else returns false
		void enqueue(ElementType itemToEnqueue);
		//Gets an item as an input
		//Adds the item at the end of queue, increases queueSize
		void dequeue();
		//Deletes the item at the head of queue, decreases queueSize
		ElementType front();
		//Shows the item at the head of queue
		
	private:
		
		class Node{
			public:
				ElementType data;
				Node *next;
		};

		Node* head;
		Node* last;
		int queueSize;
};
#endif

