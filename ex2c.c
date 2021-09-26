#include<stdio.h>
#include<omp.h>

int main(void)
{
  int n, sum = 0;
  printf("Enter the value of n: ");
  scanf("%d", &n);
  
  #pragma omp parallel for firstprivate(sum)
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=i;j++)
    {
      if(i%j==0)
      {
        sum = sum + j;
      }
    }
    printf("\nFactor of the number %d is: %d", i, sum);
  }
} 
