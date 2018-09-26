//main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cassert>

#include <stack>
#include <queue>

using namespace std;

void openInputFile(ifstream &myfile);
//Asks a file name from the user, opens if it's available, if not returns warning message via assert
void openOutputFile(ofstream &myfile);
//Asks a file name from the user, creates an output file in that name.
queue<std::string> infixToPostfix(string exp);
//Seperates the lines of the expressions in the file.
void evalQueue(ofstream & myoutfile, queue<std::string> & q);
//Gets the lines of information provided by getQueue, in queue form.
//Evaluates the postfix expressions using stack methods.
//Calculates and writes the results of expressions into the output file.
int checkPrecedence(char operation);
//Gets an operator, appoints representing values to the operators.
//returns a value to check precedence of an operator compared to another operator.
int calculation(int operand1, int operand2, char operation);
//Gets two operands and operator as an input, performs the respective operation
//Returns the result of the operation.

int main(){

	ifstream myfile;	
	openInputFile(myfile);
	ofstream myoutfile;	
	openOutputFile(myoutfile);
	string line;
	while(getline(myfile, line)){
		
		queue<string> q = infixToPostfix(line);	
		evalQueue(myoutfile, q);
		
	}
	
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

queue<std::string> infixToPostfix(string exp){
	
	queue<std::string> q;
	stack<std::string> s;	
	

		
		stringstream lineStream(exp);
		string token;	
			
		while(lineStream){
			lineStream >> token;
			if(token[0] == '0' || atoi(token.c_str())){
				q.push(token);
			}
			
			else if(token == "("){
			
				s.push(token);
			}
			
			else if(token == ")"){
				
				while(s.top() != "("){
					q.push(s.top());
					s.pop();
				}
				s.pop();
			}

			else if(token != "#"){
				
				while(!s.empty() && checkPrecedence(token[0]) <= checkPrecedence(s.top()[0])){
					q.push(s.top());
					s.pop();
				}
				
				s.push(token);
				
			}
			
		}
		
		while(!s.empty()){
			q.push(s.top());
			s.pop();
		}
	
	return q;
	
}

void evalQueue(ofstream & myoutfile, queue<std::string> & q){ 
		
	 	myoutfile << "Result of the expression ";
		stack<int> s;
		while(!q.empty()){	
	
			string token = q.front();
			myoutfile << token << " ";
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
		q.pop();
		
		}
		myoutfile << " is: " << s.top() << endl;
}
int calculation(int operand1, int operand2, char operation){
	
	switch(operation){
		
	case '*':
		return operand2 * operand1;
    case '+': 
		return operand2 + operand1;
    case '-': 
		return operand2 - operand1;
    default : 
		return 0;
	}
}

int checkPrecedence(char operation){
	
	int value;
		
	switch(operation){
			
		case '*': 
	    	value = 3;
			return value;
	    case '+': 
		case '-': 
			value = 2;
			return value;
		case '(': 
			value = 1;
			return value;
	    default : 
			return 0;
		}	
}
