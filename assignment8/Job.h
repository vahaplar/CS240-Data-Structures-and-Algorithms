//Job.h

#ifndef JOB
#define JOB

#include<iostream>
using namespace std;

class Job {


	public:
		Job();
		
		Job(int idNumberIn, int timeIn, int priorityIn, int completionIn);
		
		int getId() const;
		
		int getTime() const;
		
		int getPriority() const;
		
		int getCompletion() const;
		
		friend bool operator<(const Job &j1, const Job &j2);
		
	private:
		int idNumber;
		int time;
		int priority;
		int completion;
};
		
#endif

