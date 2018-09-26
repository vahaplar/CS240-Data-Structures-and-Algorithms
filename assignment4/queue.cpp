//queue.cpp
#include "queue.h"

Queue::Queue(){
	head = NULL;
	last = NULL;
	queueSize = 0;
}
		
Queue::~Queue(){
	
	int sizeCount = queueSize;
	for(int i = 0 ; i < sizeCount ; i++) dequeue();
	queueSize = 0;
	head = NULL;
}
		
int Queue::size(){
	
	return queueSize;
}
		
bool Queue::empty(){
	
	return (queueSize == 0);
}
		
void Queue::enqueue(ElementType itemToEnqueue){
	
	Node *temp = new Node;

    temp->data = itemToEnqueue;
    temp->next = NULL;
	
	if(head == NULL){

        head = temp;
    }
	
	else{

        last->next = temp;
    }

    last = temp;
    queueSize++;
}
		
void Queue::dequeue(){
	
	Node *temp = new Node;

    if(head == NULL){
	return;	
    }
	
	else{

        temp = head;
        head = head->next;


        delete temp;
    }
   
    queueSize--;
}
		
ElementType Queue::front(){
	return head->data;
}
