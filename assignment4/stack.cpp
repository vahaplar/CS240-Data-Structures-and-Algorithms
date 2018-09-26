//stack.cpp
#include "stack.h"
#include <cassert>

Stack::Stack(){
	head = NULL;
	stackSize = 0;
}

Stack::~Stack(){
	
	int sizeCount = stackSize;
	for(int i = 0 ; i < sizeCount ; i++) pop();
	stackSize = 0;
	head = NULL;
}

int Stack::size() const{
	return stackSize;
}
		
bool Stack::empty() const{
	return (stackSize == 0);
}
		
void Stack::push(ItemType item){
	
	Node* newItem = new Node;
    
	newItem->data = item;
    newItem->next = NULL;
    
    if (stackSize == 0){
        head = newItem;
        stackSize++;
        return;
    }
    
    newItem->next = head;
    head = newItem;
    stackSize++;
    return;
}

void Stack::pop(){
	
	assert(stackSize != 0);
    
    Node *pop = head;
    head = head->next;
    
    delete pop;
    stackSize--;
    
	return;
}

ItemType Stack::top() const{
	
	return head->data;
}
