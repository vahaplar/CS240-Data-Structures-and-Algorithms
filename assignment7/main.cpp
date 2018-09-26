//main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Map.h"

void openFile(ifstream& f);
//input: ifstream
//output: opens a file
//side effects: gets filename from user, prompts error message if not valid

int hashFunction(int id, int tSize);

int main(){
	
	Map bankMap(48, hashFunction);
	ifstream myFile;
	openFile(myFile);
	char op;
	string line;
	
	while(getline(myFile,line)){
		stringstream ss(line);	
		string name1;
		string name2;
		int id;
		ss >> id >> name1 >> name2;
		if (!bankMap.add(id, new BankAccount(id, name1 + " " + name2, 0))){
			std::cout << std::endl << id << " already has an account - not added" << std::endl;
		}
		
	}
	
	while (true){
    
    string selection;
    cout << "Selections: list, deposit, withdraw, display, close, quit " <<endl;
    cin >> selection;
    
    
    if(selection == "list") {
      
      	bankMap.displayItems(cout);
		
		bankMap.displayStats(cout);
      
    } 
	
	else if(selection == "deposit"){
      	
      	int idToDeposit;
      	cout << "Enter the ID of the account you want to deposit: ";
    	cin >> idToDeposit;
    	BankAccount *account = bankMap.retrieve(idToDeposit);
        
      	if(account == NULL) {
          
       		 cout << "Error: Invalid account name!" << endl;
      	} 
	  
		else{
          
    		double amount;
        	cout << "Enter the amount of money you want to deposit in the following account:" << endl <<"ID: " << idToDeposit << endl << "Name: " << account->getName() << endl;
      	    cin >> amount;
        
			account->deposit(amount);
        
			cout << "New balance is: $" << account->getBalance() << endl;
    	}
      
    }
	
	else if(selection == "withdraw"){

      
    	int idToWithdraw;
    	cout << "Enter the ID of the account you want to withdraw: ";
    	cin >> idToWithdraw;
      	BankAccount *account = bankMap.retrieve(idToWithdraw);
        
      	if(account == NULL) {
          
        	cout << "Error: Invalid account name!" << endl;
     	} 
	  
		else{
          
        	double amount;
        	cout << "Enter the amount of money you want to withdraw from following account:" << endl <<"ID: " << idToWithdraw << endl << "Name: " << account->getName() << endl;
       		 cin >> amount;
        		
       		account->withdraw(amount);
        	cout << "New balance is: $" << account->getBalance() << endl;
     	}
      
    } 
	
	else if(selection == "display"){

     	 int idToDisplay;
     	 cout << "Enter the ID of the account you want to display: ";
      	cin >> idToDisplay;
      	BankAccount *account = bankMap.retrieve(idToDisplay);
        
     	 if(account == NULL) {
          
		  cout << "Error: Invalid account name!" << endl;
        
      	} 
	  
		else{
    	cout << *account << endl;
      
	  	}
      
    } 
	
	else if(selection == "close"){
      
    	int idToDelete;
   		 cout << "Enter the ID of the account you want to delete: ";
   	 	cin >> idToDelete;
   	 	BankAccount *account = bankMap.remove(idToDelete);
        
   		if(account == NULL) {
          
			  cout << "Error: Invalid account name!" << endl;
        
    	} 
	  
		else{
    		cout << "Following account has been deleted: "<< endl <<"ID: " << idToDelete << endl << "Name: " << account->getName() << endl;
    		delete account;
    	}
      
    } 
	
	else if(selection == "quit") {
      
    	cout << "Terminated!" << endl;
    	break;
      
    }
  }
}


int hashFunction(int id, int tSize){
	return id % tSize;
}


void openFile(ifstream& f){
	string fileName;
	cout << "Enter the input file : " ;
	cin >>fileName;		
	f.open(fileName.c_str());	
	while(!f.is_open()){	 
		cout << fileName << " could not be opened - Enter again" << endl;
		cin >> fileName;
		f.open(fileName.c_str());
	}
}


