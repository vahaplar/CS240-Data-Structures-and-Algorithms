#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "SimpleList.h"
#include "player.h"

using namespace std;

void splitString(const string &line, char delimiter, string arr[]);
//input: lines of player information, delimiter
//output: none
//side effects: splits lines of player information and puts them into array elements

void showInstructions();
//input: none
//output: none
//side effects: prints instructions for user.
  	
int main (){
	
	SimpleList l1;
	string line;
	ifstream myfile ("players.txt");
  	
  	if (myfile.is_open()){
  		
  		int ranking = 1;
  		 	
		while (getline (myfile,line)){
    		
    		
			string arr[5]={""};
   			splitString(line, ' ', arr);
			
			TennisPlayer tp1(arr[0], arr[1], ranking , atoi(arr[2].c_str()), arr[3]+" "+arr[4]);    	
			l1.insert(tp1,ranking-1);
    		++ranking;
		
		}		
  		
		myfile.close();		
		
  		char choice;
		
		while(choice != 'Q'){
		
		showInstructions();
		
		cin >> choice;
		
		/*I couldn't decompose the parts of switch case, so if it's also a part of assignment code is missing this point.
		The reason why I state this is that the program could be consisted of different functions which could
		get user input as well as list info and print respective information as a side effect. Instead, only the methods were invoked here */
			switch(choice){
				case 'I':
				case 'i':
					{
						int position;
						cout << "Please enter a position: ";
						cin >> position;
						
						if(position <= 0 || position > 20)
							cout << "Invalid position entered!" << endl;
						else{
							TennisPlayer player;
							player = l1.retrieve(position-1);
						
							cout << "Player name: " << player.getFirstName() << " " << player.getLastName() << endl;
							
						}					
					}
				break;
				case 'P':
				case 'p':
					{
						string lastName;
						cout << "Please enter last name: ";
						cin >> lastName;
						bool status = false;
						TennisPlayer player;
						
							for(int i=0; i < l1.listSize(); i++){
								
								player = l1.retrieve(i);
								if(player.getLastName() == lastName){
									status = true;
									break;								
								}
								
							}
							
							if(status){
								cout << "Player's position is: " << player.getRanking() << endl;
							}else
								cout << "Not found!" << endl;
					}
				break;
				case 'D':
				case 'd':
					{					
						TennisPlayer player1, player2;
						int position;
						
						cout << "Please enter the first position: ";
						cin >> position;
						
						if(position <= 0 || position > 20)
							cout << "Invalid position entered!" << endl;
						
						else{
							
							player1 = l1.retrieve(position - 1);
							
							cout << "Please enter the second position: ";
							cin >> position;
							
							if(position <= 0 || position > 20)
								cout << "Invalid position entered!" << endl;
							
							else{
								player2 = l1.retrieve(position - 1);
								int difference = player1.getPointTotal() - player2.getPointTotal();
								
								if(difference<0) difference *= -1;
								
								cout << "The difference is: " << difference << endl;
							}		
						}
					}
				break;
				
				case 'Q':
				case 'q':
				{
					cout << "Terminated!";
				}
				break;
			}
	
		}	
	
  	}
  	
	else cout << "Unable to open file!"; 

  	return 0;
}

void showInstructions(){
	
    cout << "Instructions:" << endl;
    cout << "I - Access player information by entering player ranking." << endl;
    cout << "P - Learn player's position by entering the player's last name." << endl;
    cout << "D - Find the point difference between players by entering their positions." << endl;
    cout << "Q - Quit!" << endl << endl;
    cout << "Selection: " << endl;

}

void splitString(const string &line, char delimiter, string arr[]){

	istringstream ss(line);
	string token;
	int i = 0;
	
	while(getline(ss, token, delimiter)) {
	    arr[i] = token;
	    i++;
	}	
}
