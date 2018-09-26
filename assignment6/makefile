main.exe:Set.o main.o
	g++ Set.o main.o -o main.exe
Set.o:Set.cpp Set.h
	g++ -c Set.cpp
main.o:main.cpp Set.h
	g++ -c main.cpp
clean:
	rm *.o main.exe 
	
