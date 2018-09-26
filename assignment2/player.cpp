#include "player.h"	
#include <cstdlib>

//player.cpp file was completed in lab2 as a lab assignment

TennisPlayer::TennisPlayer(){
	firstName = " ";
	lastName = " ";
    ranking = 0;
	pointTotal = 0;
	country = " ";
}

TennisPlayer::TennisPlayer(string initFirstName, string initLastName, int initRanking, int initPointTotal, string initCountry){
	
	firstName = initFirstName;	
	lastName = initLastName;
	ranking = initRanking;
	pointTotal = initPointTotal;
	country = initCountry;
}

string TennisPlayer::getFirstName() const{
	return firstName;
}

string TennisPlayer::getLastName() const{
	return lastName;
}

int TennisPlayer::getRanking() const{
	return ranking;
}

int TennisPlayer::getPointTotal() const{
	return pointTotal;
}

string TennisPlayer::getCountry() const{
	return country;
}

void TennisPlayer::setRanking(int ranking){
	
	this->ranking = ranking;
}

void TennisPlayer::setPointTotal(int pointTotal){
	
	this->pointTotal = pointTotal;
}

ostream & operator<< (ostream & out, const TennisPlayer & f){
	out << f.firstName << " " << f.lastName << " " << f.ranking << " " << f.pointTotal << " " << f.country;
	return out;
}
