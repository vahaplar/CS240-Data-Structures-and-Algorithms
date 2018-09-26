//main.cpp
#include "stack.h"
#include "queue.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cassert>

void openInputFile(ifstream &myfile);
//Asks a file name from the user, opens if it's available, if not returns warning message via assert
void openOutputFile(ofstream &myfile);
//Asks a file name from the user, creates an output file in that name.
int calculation(int operand1, int operand2, char operation);
//Gets two operands and operator as an input, performs the respective operation
//Returns the result of the operation.
Queue getQueue(ifstream &myfile);
//Seperates the lines of the expressions in the file.
void evalQueue(ofstream & myoutfile, Queue & q);
//Gets the lines of information provided by getQueue, in queue form.
//Evaluates the postfix expressions using stack methods.
//Calculates and writes the results of expressions into the output file.

int main(){

	ifstream myfile;	
	openInputFile(myfile);
	ofstream myoutfile;	
	openOutputFile(myoutfile);
	Queue q = getQueue(myfile);	
	evalQueue(myoutfile, q);
	
	return 0;
}

void openInputFile(ifstream &myfile){
	
	string fileName;
	
	cout<< "Enter input file name: ";
	cin >> fileName;
	
	myfile.open(fileName.c_str());
	assert(myfile.is_open()!=false);
}

void openOutputFile(ofstream &myfile){
	
	string fileName;
	
	cout<< "Enter output file name: ";
	cin >> fileName;
	
	myfile.open(fileName.c_str());
	assert(myfile.is_open()!=false);
}

int calculation(int operand1, int operand2, char operation){
	
	switch(operation){
		
	case '*': 
		return operand2 * operand1;
    case '/': 
		return operand2 / operand1;
    case '+': 
		return operand2 + operand1;
    case '-': 
		return operand2 - operand1;
    default : 
		return 0;
	}
}

Queue getQueue(ifstream &myfile){
	
	Queue q;	
		string line;		
	
	while(getline(myfile,line)){
	
		q.enqueue(line);
	}
	
	myfile.close();
	
	return q;
	
}

void evalQueue(ofstream & myoutfile, Queue & q){
		
		while(!q.empty()){	
	
		string exp = q.front();
		stringstream lineStream(exp);
		Stack s;
		
		string token;
		
		do{
			lineStream >> token;
			if(token[0] == '0' || atoi(token.c_str())){
				s.push(atoi(token.c_str()));
			}
			
			else if(token != "#"){
				int op1 = s.top();
				s.pop();
				int op2 = s.top();
				s.pop();
				s.push(calculation(op1, op2, token[0]));
			}
		}
		
		while(token != "#");
		
		myoutfile << "Result of the expression " << exp << " is: " << s.top() << endl;
		
		q.dequeue();
	}
}
