#include <iostream>
using namespace std;

void getName(string &name, string &surname);
// input: name and surname 
// output: none
// side effects: promts user to input name and surname

int getAge();
// input: none
// output: age
// side effects: promts user to input an age value

void display(const string name,const string surname,const int age);
// input: name surname and age value
// output: none
// side effects: it displays the values in the order of "surname" "name" and "age"

int main (){
	
	string name,surname;
	getName(name, surname);
	int age = getAge();
	display(name, surname, age);
	return 0;
}

void getName(string &name, string &surname){
	
	cout << "Enter your name and surname: ";
	cin >> name >> surname;
}

int getAge(){
	
	int age;
	cout << "Enter your age: ";
	cin >> age;
	
	if (age>=0 && age<=125) return age;
	else getAge();

}

void display(const string name,const string surname, const int age){
	
	cout << surname << " "<< name << " " << age;
	
}
