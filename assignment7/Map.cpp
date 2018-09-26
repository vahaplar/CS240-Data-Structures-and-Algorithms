//Map.cpp

#include "Map.h"

Map::Map(int size, hashFunc func){
	hashTable.resize(size);
	hashFunction = func;
}	

bool Map::empty() const{
	return size()==0;
}

int  Map::size() const{
	int count = 0;
	for(auto &i : hashTable)
		for(auto &j : i)
			count++;
	
	return count;
}
		 
bool  Map::find(const KeyType & key) const{
	int hash = hashFunction(key, hashTable.size());
	
	
	for(auto &i : hashTable[hash])
		if(i.first == key)
			return true;
		
	return false;
}

bool  Map::add(const KeyType & key, const ValueType & item){
	
	if(find(key))
		return false;
	
	int hash = hashFunction(key, hashTable.size());
	hashTable[hash].push_back(make_pair(key, item));
	return true;
	
}
		 	
ValueType  Map::retrieve(const KeyType & key) const{
	
	int hash = hashFunction(key, hashTable.size());
	for(auto &i : hashTable[hash])
		if(i.first == key)
			return i.second;

}
		 
ValueType  Map::remove(const KeyType & key){
	int hash = hashFunction(key, hashTable.size());
		for(list < pair < KeyType , ValueType > > :: iterator i = hashTable[hash].begin(); i != hashTable[hash].end(); i++)
			if(i->first == key){
				ValueType ret = i->second;
				hashTable[hash].erase(i);
				return ret;
			}
	return NULL;
}

void Map::displayItems(std::ostream & out) const {
	
	
	for(auto &i : hashTable)
		for(auto &j : i)
			out << *(j.second) << endl;
}

void Map::displayStats(std::ostream & out) const {
	
	double sum = 0;
	double haselem = 0;
	int longest;
	
	out << "Load factor: " << (double) size() / hashTable.size() << endl;
	 
	
	for(auto &i : hashTable)
		if(i.size() > 0){
			if(i.size() > longest)
				longest = i.size();	
			sum += i.size();
			haselem++;
		}
		
	out << "Longest synonym list size: " << longest << endl;
	
	out << "Average: " << sum / haselem << endl;
	
}
