// BankAccount.cpp

#include "BankAccount.h"

BankAccount::BankAccount(){
	name = "anonymous";
	id = 000000;
	balance = 0;
}

BankAccount::BankAccount(int idIn, string nameIn, double balanceIn){
	id = idIn;
	name = nameIn;
	balance = balanceIn;
}

void BankAccount::deposit (double amount){
	balance += amount;
}

void BankAccount::withdraw (double amount){
	balance -= amount;
}

int BankAccount::getId () const{
	return id;
}

string BankAccount::getName () const{
	return name;
}

double BankAccount::getBalance () const{
	return balance;
}

ostream& operator<<(ostream & out, const BankAccount & b){
	out << b.id << "   " << b.name << "   " << b.balance << endl;
}

bool BankAccount::operator<(const BankAccount &first) const{
	
	return balance < first.getBalance();

}

