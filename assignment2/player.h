#ifndef TENNISPLAYER
#define TENNISPLAYER

#include <iostream>
using namespace std;

//player.h file was completed in lab2 as a lab assignment
class TennisPlayer{
	public:
		TennisPlayer();
		//creates a TennisPlayer object with 0 items in it
		
		TennisPlayer(string initFirstName, string initLastName, int initRanking, int initPointTotal, string initCountry);
		// TennisPlayer object with default items
		
		string getFirstName() const;
		//input: none
		//output: first name
		//side effects: none
		
		string getLastName() const;
		//input: none
		//output: last name
		//side effects: none		
		
		int getRanking() const;	
		//input: none
		//output: ranking (position)
		//side effects: none
		
		int getPointTotal() const;
		//input: none
		//output: total point
		//side effects: none
		
		string getCountry() const;		
		//input: none
		//output: country information
		//side effects: none
				
		void setRanking(int ranking);
		//input: position of player
		//output: none
		//side effects: sets a new ranking value to the current value 
		
		void setPointTotal(int pointTotal);
		//input: total point
		//output: none
		//side effects: sets a new total point value to the current value 
		
		friend ostream& operator<< (ostream & out, const TennisPlayer & f);
		// sends the value of f to out
		
	private:
		string firstName;
		string lastName;
		int ranking;
		int pointTotal;
		string country;
};
#endif

