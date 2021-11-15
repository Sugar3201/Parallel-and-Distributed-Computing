#include<stdio.h>
#include<omp.h>

int main(void)
{
	int x=0;
	int y=0;
	int z=0;
	
	#pragma omp parallel shared(x)
	{
		#pragma omp critical
		x = x+1;
		
		#pragma omp master
		y = y+1;
		
		#pragma omp single
		z = z+1;	
	}
	
	printf("By using the critical value of x: %d", x);
	printf("By using the master value of y: %d", y);
	printf("By using the single value of z: %d", z);
}
