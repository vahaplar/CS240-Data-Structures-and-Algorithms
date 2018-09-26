main.exe:BankAccount.o Map.o main.o
	g++ BankAccount.o Map.o main.o -o main.exe
BankAccount.o:BankAccount.cpp BankAccount.h
	g++ -c -std=c++11 BankAccount.cpp
Map.o:Map.cpp Map.h
	g++ -c -std=c++11 Map.cpp
main.o:main.cpp Map.h BankAccount.h
	g++ -c -std=c++11 main.cpp
clean:
	rm *.o main.exe 