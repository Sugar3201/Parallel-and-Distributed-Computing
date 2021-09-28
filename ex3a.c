#include<stdio.h>
#include<omp.h>

int main(void)
{
  int cube;
  int a[] = {1,2,3,4};
  #pragma omp parallel for lastprivate(cube)
  for(int i = 0; i < 4; i++)
  {
    cube = a[i]*a[i]*a[i];
    printf("\nCube of number in %dth index: %d", i, cube);
  }
  printf("\nCube of the max value(value in last index): %d", cube);
}
