main.exe:queue.o stack.o main.o
	g++ queue.o stack.o main.o -o main.exe
queue.o:queue.cpp queue.h
	g++ -c queue.cpp
stack.o:stack.cpp stack.h
	g++ -c stack.cpp
main.o:main.cpp stack.h queue.h
	g++ -c main.cpp
clean:
	rm *.o main.exe 
	
