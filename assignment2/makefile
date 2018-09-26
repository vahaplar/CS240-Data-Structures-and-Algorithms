main.exe: main.o player.o SimpleList.o
	g++ main.o player.o SimpleList.o -o main.exe

main.o: main.cpp player.h SimpleList.h
	g++ -c main.cpp
	
player.o: player.cpp player.h
	g++ -c player.cpp
	
SimpleList.o: SimpleList.cpp SimpleList.h
	g++ -c SimpleList.cpp
	
clean: 
	rm *.o main.exe
