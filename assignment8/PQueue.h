//PQueue.h

#ifndef PQUEUE
#define PQUEUE

#include "Job.h"
#include<iostream>
using namespace std;

typedef Job *ElementType;

class PQueue {
// defines a data type to represent a priority queue

	public:

		PQueue();
		//Queue constructor
		~PQueue();
		//Destructor
		int size();
		//Returns the size of PQueue
		bool empty();
		//Returns true if PQueue is empty, else returns false
		void enqueue(ElementType itemToEnqueue);
		//Gets an item as an input
		//Adds the item at the end of queue, increases PQueueSize
		void dequeue();
		//Deletes the item at the head of queue, decreases PQueueSize
		ElementType front();
		//Shows the item at the head of queue
		
	private:
		
		ElementType heap[15];
		int _size;
		
		void dequeueHelper(int i);
		
};
		
#endif
