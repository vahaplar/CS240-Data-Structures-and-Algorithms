main.exe:Job.o JobScheduler.o PQueue.o main.o
	g++ Job.o JobScheduler.o PQueue.o main.o -o main.exe
Job.o:Job.cpp Job.h
	g++ -c -std=c++11 Job.cpp
JobScheduler.o:JobScheduler.cpp JobScheduler.h
	g++ -c -std=c++11 JobScheduler.cpp
PQueue.o:PQueue.cpp PQueue.h
	g++ -c -std=c++11 PQueue.cpp
main.o:main.cpp Job.h JobScheduler.h PQueue.h
	g++ -c -std=c++11 main.cpp
clean:
	rm *.o main.exe 