#include<stdio.h>
#include<omp.h>

int main(void)
{
  int n, k = 0, l = 0;
  printf("Enter the value of n: ");
  scanf("%d", &n);
  
  int fib[n], prime[n], fact[n];
  
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      fib[0] = 1;
      if( n > 1)
      {
        fib[1] = 1;
        for(int i = 2; i < n; i++)
        {
          fib[i] = fib[i-1] + fib[i-2];
        }
      }
    }
    #pragma omp section
    {
      for(int i = 1; i <= n; i++)
      {
        if(n%i == 0)
        {
          fact[k++] = i;
        }
      }
    }
    #pragma omp section
    {
      for(int i = 2; i <= n; i++)
      {
        int isPrime = 0;
        for(int j = 2; j< i ; j++)
        {
          if( i%j == 0)
          {
             isPrime  = 1;
          }
        }
        if(isPrime == 0)
        {
          prime[l++] = i;
        }
      }
    }
  }
  printf("\nFibonacci Series:");
  for(int i = 0; i < n; i++)
  {
    printf(" %d", fib[i]);
  }
  printf("\nFactorial of number %d:", n);
  for(int i = 0; i < k; i++)
  {
    printf(" %d", fact[i]);
  }
  printf("\nPrime numbers upto %d:", n);
  for(int i = 0; i < l; i++)
  {
    printf(" %d", prime[i]);
  }
}
