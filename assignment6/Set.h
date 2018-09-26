// Set.h
#ifndef SET
#define SET

#include<iostream>
using namespace std;

typedef string ItemType;     // type of item to be stored

class Set{

    public:
        Set();
        // creates a Set object with 0 items in it
		
		~Set();
		// destructor
		
		Set(const Set &object);
		// copy constructor
		
        bool empty () const;
        // returns true if Set object holds 0 items
        
        int getSize ()const;
        // returns number of items in Set
        
        bool add (const ItemType & item);
        // adds item to the set and returns true; else, false
               
        bool find (const ItemType & item);
        // returns true if item is in the set
        // returns false if item is not in the set
        
        bool remove(const ItemType & item);
        // removes item from the set and returns true if item is
	    // in the set; otherwise returns false
        
        void display (ostream & out) const;
        // sends items in the Set to the ostream provided
        
		int getHeight();
        // returns height of Set
                    
 	private:
		
		class Node{
 			public:  
			 	Node *parent;  
		   		Node *left;
            	Node *right;
            	ItemType data;
 		};
 		
		 Node *root;
		
 		 int size;
 		 int height;
		
		
		void deleteRec(Node* node);
		//input: node pointer
		//output: none
		//side effects: recursive call to delete tree nodes
		void copyRec(Node* node);
		//input: node pointer
		//output: none
		//side effects: recursive call to copy tree nodes
	
		bool addRec(Node * node, const ItemType & item);
		//input: node pointer, item
		//output: boolean to check if addition successful or not
		//side effects: recursively adding the item in the set.
		
		bool findRec (Node * node, const ItemType & item);
		//input: node pointer, item
		//output: boolean to check if the item is in the set or not
		//side effects: recursively finds the item in the set
				
		
		bool removeRec (Node * node, const ItemType & item);
		//input: node pointer, item
		//output: boolean to check if the item is in the set or not
		//side effects: recursively remove the item in the set
		
		int heightRec(Node* node);
		//input: node pointer, item
		//output: integer value for height of the tree
		//side effects: recursively calls itself to calculate height value.
		
		void displayRec(std::ostream & out, Node* node) const;
		//input: node pointer, output stream
		//output: none
		//side effects: recursively calls itself to display the items in the tree.
		
}; 
#endif   
        
