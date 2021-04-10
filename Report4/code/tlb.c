#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char* argv[]){
	cpu_set_t cpuset;
	pthread_t thread = pthread_self();
	CPU_ZERO(&cpuset);
	int a;
	a = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);

	struct timespec start, end;
	double diffTime = 0;
	FILE* file =fopen("result.txt", "a");
	int NUMPAGES = atoi(argv[1]);
	printf("NUMPAGES : %d \n", NUMPAGES);
	int TRIALS = atoi(argv[2]);
	printf("TRIALS : %d \n", TRIALS);
	int PAGESIZE = sysconf(_SC_PAGESIZE);
	printf("PAGESIZE : %d \n", PAGESIZE);
	int *array = (int*)calloc(NUMPAGES*PAGESIZE, sizeof(int));
	int jump = PAGESIZE / sizeof(int);
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i = 0; i<TRIALS;i++){

		for (int j=0;j<NUMPAGES * jump;j+=jump){
			array[j] += 1;
		}
	}
	/*
	for (int i=0;i<NUMPAGES*PAGESIZE;i++){
		printf("%d ", array[i]);
	}
	*/
	clock_gettime(CLOCK_MONOTONIC, &end);
	diffTime = (end.tv_sec-start.tv_sec) +(end.tv_nsec-start.tv_nsec)*1e-9;
	//printf("%.9f s", diffTime);
	printf("avg time for NUMPAGES(%d), TRIALS(%d) : %.9f s\n", NUMPAGES, TRIALS, diffTime/TRIALS);
	fprintf(file, "%.9f\n", diffTime/TRIALS);
	fclose(file);
	return 0;
}
