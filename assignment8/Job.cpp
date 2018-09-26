//Job.cpp

#include "Job.h"

Job::Job(){
	idNumber=000;
	time=0;
	priority=0;
	completion=0;
}
		
Job::Job(int idNumberIn, int timeIn, int priorityIn, int completionIn){
	idNumber=idNumberIn;
	time=timeIn;
	priority=priorityIn;
	completion=completionIn;
}
		
int Job::getId() const{
	return idNumber;
}
		
int Job::getTime() const{
	return time;
}
		
int Job::getPriority() const{
	return priority;
}
		
int Job::getCompletion() const{
	return completion;
}
		
bool operator<(const Job &j1, const Job &j2){
	    return (j1.priority < j2.priority);
	
}
