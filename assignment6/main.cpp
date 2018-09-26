//main.cpp
#include "Set.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cassert>

using namespace std;

void openInputFile(ifstream &myfile);

int main(){
	
	ifstream myfile1;	
	Set set;
	string line;
	
	openInputFile(myfile1);
	
	while(getline(myfile1, line)){
		set.add(line);
	}
	
	cout<<"Size of the set is: "<<set.getSize()<<endl;
	cout<<"Height of the set is: "<<set.getHeight()<<endl;
	set.display(cout);
	myfile1.close();
	
	
	ifstream myfile2;
	openInputFile(myfile2);
	int spammer = 0;
	int notSpammer = 0;
		
	while(getline(myfile2, line)){
		
		if(set.find(line)){
			spammer++;
		}
		else notSpammer++;
	}
	
	cout<<"Number of good adresses is: "<<notSpammer <<endl;
	cout<<"Number of bad adresses is: "<<spammer <<endl;
	myfile2.close();
	
	ifstream myfile3;
	openInputFile(myfile3);
	
	while(getline(myfile3, line)){
		set.remove(line);
	}
	cout<<"Size of the set is: "<<set.getSize()<<endl;
	cout<<"Height of the set is: "<<set.getHeight()<<endl;
	set.display(cout);
	myfile3.close();
	
	return 0;
}

void openInputFile(ifstream &myfile){
	
	string fileName;
	
	cout<< "Enter input file name: ";
	cin >> fileName;
	
	myfile.open(fileName.c_str());
	assert(myfile.is_open()!=false);
}
