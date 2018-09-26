#include "SimpleListL.h"
/*
Notes on revised Assignment 3:

The first Assignment 3 I submitted had several big mistakes and one missing part(iterator 
methods) even so my code was compiling and running.
In this revise, I fixed my Phase 2 functions to work properly and in harmony with testerAss3.cpp 
provided by the Instructor. Remove function has changed the most.

My previous versions of "Big Three" methods were very insufficent, so they are revisited.
Although they're not included in the grade of revised Assignment3, I wanted them to be 
complete for the sake of future assignments. Also the missing iterator methods are included now.
*/

SimpleList::SimpleList(){
	// create a SimpleList object with 0 items in it
	head = NULL;
	last = NULL;
	size = 0;
}
/*
SimpleList::~SimpleList(){
	//Destructor
	int sizeCount = size;
	for(int i = 0 ; i < sizeCount ; i++) remove(1);
	size = 0;
	head = NULL;
	last = NULL;
}

SimpleList::SimpleList(const SimpleList& object){
	//Copy Constructor
	size = 0;
	head = NULL;
	last = NULL;
	
	for(int i = 0; i < object.size ; i++){
			append(object.retrieve(i+1));
		}
}
	
SimpleList& SimpleList::operator=(const SimpleList& object){
	//Copy assignment operator
	int sizeCount = size;
	for(int i = 0 ; i < sizeCount ; i++) remove(1);
	size = 0;
	head = NULL;
	last = NULL;
	
	for(int i = 0; i < object.size ; i++){
		append(object.retrieve(i+1));
	}
	
	return *this;
}
*/

bool SimpleList::empty() const{
	return (size == 0);
}

int SimpleList::listSize() const{
	return size;
}

void SimpleList::append(const ItemType & item){
	// insert item at the end of SimpleList
	Node *append = new Node;
	append->data = item;
	
	if(size == 0){	
		head = last = append;
	}
	
	else{
		last->next = append;
		last = append;
	}
	
	append->next = NULL;
	
	size++;
	
}

void SimpleList::display (ostream & out) const{
		// sends items in SimpleList to the ostream provided
        // precondition: operator<< is defined for ItemType
	
		Node *item = head;
	
		while(item != NULL){
			out << item->data << endl;
			item = item->next;
		}

}

void SimpleList::insert (const ItemType & item, int position){
		// insert item at the specified position
		// precondition: position > 0 and position <= number of items + 1
	if(position <= 0 || position > size+1)
		return;
	
	if(position > 0 && position <= listSize()+1){
	
	Node *insert = new Node();
	insert->data = item;
		
		if(listSize() == 0){	
			head = insert;
		}

		else if (position == 1){
			
			insert->next = head;
			head = insert;
		} 
	
		else{
			
			Node *current = head;	
			int count = 0;
			
			while (count < position - 2 && current != NULL){
				current = current->next;
				count++;
			}
	
			insert->next = current->next;
			current->next = insert;
		}

	size++;
	
	}
	
	else{
		cout << "No such position!" << endl;
	}
}
		
        
ItemType SimpleList::retrieve (int position)const{
        // return item at specified position
        // precondition: position > 0 and position <= number of items
        Node *item = head;

		if(position > 0 && position <= listSize()){
		
			for(int i=1;i<position;i++){
		
			item = item->next;
			}
			
			return (*item).data;
		}
}

        
void SimpleList::remove (int position){
        // remove item at specified position
        // precondition: position > 0 and position <= number of items

		Node *current = head;
		Node *prev;
		
		if(position > 0 && position <= listSize()){
			
			if(size == 1){
				delete current;
				head = NULL;
				last = NULL;
				size = 0;
				return;
			}
			
			if(position == 1){
				if(current -> next != NULL)
					head = current->next;
				delete current;
				size --;
				return;
			}
			
			
			for(int i=1;i<position;i++){
			prev = current;
			current = current->next;
			}
			
			if(position == size){
				last = prev;
				last->next = NULL;
				delete current;
				size--;
				return;
			}
			
			prev->next = current->next;
			delete current;
			size--;
		}
		return;
}

/*Iterator methods.
void SimpleList::moveToStart(){
	current = head;
}

bool SimpleList::pastTheEnd(){
	return(current==NULL);
}

void SimpleList::next(){
	current = current->next;
}
ItemType SimpleList::getItem(){
	return current->data;
}*/
