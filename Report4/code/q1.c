#include <stdio.h>
#include <time.h>

int main(){
	struct timespec startTime, endTime;
	/*
	struct timespec{

		time_t tv_sec; //seconds
		long tv_nsec;  // nanoseconds
	}
	*/
	clock_gettime(CLOCK_MONOTONIC, &startTime);
	//some operation
	int sum = 0;
	int itr = 100000;
	for (int i=0;i<itr;i++){
		sum += 1;
	}
	clock_gettime(CLOCK_MONOTONIC, &endTime);
	long sec = endTime.tv_sec - startTime.tv_sec;
	long nsec = endTime.tv_nsec - startTime.tv_nsec;
	double diffTime = sec + nsec*1e-9;
	printf("time measured : %.9f s \n", diffTime);

	return 0;
}
