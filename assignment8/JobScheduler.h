//JobScheduler.h

#ifndef JOBSCHEDULER
#define JOBSCHEDULER

#include<iostream>
using namespace std;

// Clarification: Because I missed the part of the class where Job Scheduler explained I couldn't totally master in this subject and because of the same reason
// I wasn't able to continue with the rest of the program. Although this is not an acceptable excuse, I still don't want it to be look like being neglectful.
// Thanks for your understanding.


class JobScheduler {


	public:
		JobScheduler();
		
		JobScheduler(int timeSliceIn);

	
	private:
		int timeSlice;
};
		
#endif

