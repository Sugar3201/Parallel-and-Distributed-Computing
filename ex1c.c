#include<stdio.h>
#include <omp.h>
int main ()
{ 
	int nthreads, tid;
	/* Fork a team of threads with each thread having a private tid variable */
	#pragma omp parallel private(tid) 
	{ 
		/* Obtain and print thread id */
	 	tid = omp_get_thread_num(); 
		printf("Ashish Das- Thread No: %d\n", tid);
	 	/* Only master thread does this */
	 	if (tid == 0) { 
			nthreads = omp_get_num_threads(); 
			printf("19BCE1160- Total Threads: %d && Thread ID: %d\n", nthreads, tid); 
		} 
	} 
	/* All threads join master thread and terminate */
} 
