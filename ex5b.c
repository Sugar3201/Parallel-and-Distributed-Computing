#include<stdio.h>
#include<omp.h>
#define _GNU_SOURCE
#include <sched.h>
int sched_getcpu(void);

int main(void)
{
  int a[10],b[10];
  int i, sum[10];
  
  for(i = 0; i < 10; i++)
  {
    printf("\nEnter the values of %d th a and b:",i+1);
    scanf("%d",&a[i]);
    scanf("%d",&b[i]);
  }
  
  #pragma omp parallel for schedule(dynamic, 3)
  for(i=0; i<10; i++)
  {
    sum[i] = a[i] + b[i];
    printf("For i value:%d\tCPU:%d\tThread:%d\tValue:%d\n",i+1,sched_getcpu(),omp_get_thread_num(),sum[i]);
  }
}
