//Map.h

#include "BankAccount.h"
#include<utility>  //needed for the type: pair<T1, T2>
#include<vector>  //needed for the type: pair<T1, T2>
#include<list>  //needed for the type: pair<T1, T2>

typedef int KeyType; //KeyType must be comparable using the 
			//relational operators
typedef BankAccount* ValueType;

typedef int(*hashFunc)(KeyType id, int tsize);

class Map{
	public: 
		Map(int size, hashFunc func);
		//input: none
		//output: none
		//side effects: creates an empty Map
		 	
		bool empty() const;
		//input: none
		//output: returns true if the Map is empty; else false
		//side effects: none
		 
		int size() const;
		//input: none
		//output: returns the number of elements in the Map
		//side effects: none

		bool find(const KeyType & key) const;
		//input: a key
		//output: true is an element with this key was found;
		//        else false
		//side effects: none
		
		bool add(const KeyType & key, const ValueType & item);
		//input: a key and its associated value
		//output: returns true if the key-value pair was added;
		//        else false(the key was found)
		//side effects: Map has one more element (if addition done)
		 
		ValueType retrieve(const KeyType & key) const;
		//input: a key
		//output: the value associated with key (a null
		//        pointer if the key was not found)
		//side effects: none
		 
		ValueType remove(const KeyType & key);
		//input: a key
		//output: returns true if item is removed;
		//        else false (key not found)
		//side effects: Map has one less element (if remove done)
		
		void displayItems(std::ostream & out) const;
		void displayStats(std::ostream & out) const;

		
	private:
		hashFunc hashFunction;
		vector < list < pair < KeyType , ValueType > > > hashTable;
};		
 

