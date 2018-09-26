//PQueue.cpp

#include "PQueue.h"

PQueue::PQueue(){
	_size=0;
}
		
PQueue::~PQueue(){
	
	for(int i = 0; i<_size; i++)
		delete heap[i];

}
		
int PQueue::size(){
	
	return _size;
}
		
bool PQueue::empty(){
	
	return(_size==0);
	
}
		
void PQueue::enqueue(ElementType itemToEnqueue){
	
	int i = _size;
	heap[i] = itemToEnqueue;
	++_size;
	
	while(i > 0 && *heap[(i-1)/2] < *heap[i]){
		
		ElementType temp = heap[i];
		heap[i] = heap[(i-1)/2];
		heap[(i-1)/2] = temp;
		
		i = (i-1)/2;
	}
}
		
void PQueue::dequeue(){
	
	int i = 0;
	heap[0] = heap[_size];
	heap[_size] = NULL;
	--_size;
	
	dequeueHelper(0);
	
}

void PQueue::dequeueHelper(int i){
	
	if(heap[2*i+2]!= NULL  && *heap[2*i+1] < *heap[2*i+2]){
		ElementType temp = heap[i];
		heap[i] = heap[2*i+2];
		heap[2*i+2] = temp;
		
		dequeueHelper(2*i+2);	
	}else if(heap[2*i+1] != NULL){
		ElementType temp = heap[i];
		heap[i] = heap[2*i+1];
		heap[2*i+1] = temp;
		
		dequeueHelper(2*i+1);	
	}
	
}
		
ElementType PQueue::front(){
	return heap[0];
}
