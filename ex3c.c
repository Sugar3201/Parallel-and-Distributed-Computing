#include<stdio.h>
#include<omp.h>

int main(void)
{
  int n;
  printf("Enter the number of numbers you want to enter: ");
  scanf("%d", &n);
  
  float a[n], b[n], add[n], sub[n], mul[n], div[n];
  
  for(int i = 0; i < n; i++)
  {
    printf("\nEnter the value of %dth a: ", i+1);
    scanf("%f", &a[i]);
    printf("\nEnter the value of %dth b: ", i+1);
    scanf("%f", &b[i]);
  }
  
  #pragma omp parallel sections
  {
    #pragma omp section
      for(int i = 0; i < n; i++)
      {
        add[i] = a[i] + b[i];
      }
    #pragma omp section
      for(int i = 0; i < n; i++)
      {
        sub[i] = a[i] - b[i];
      }
    #pragma omp section
      for(int i = 0; i < n; i++)
      {
        mul[i] = a[i] * b[i];
      }
    #pragma omp section
      for(int i = 0; i < n; i++)
      {
        div[i] = a[i] / b[i];
      }
  }
  for(int i = 0; i < n; i++)
  {
    printf("\nThe addition of %.2f and %.2f is : %.2f", a[i], b[i], add[i]);
    printf("\nThe subraction of %.2f and %.2f is : %.2f", a[i], b[i], sub[i]);
    printf("\nThe multiplication of %.2f and %.2f is : %.2f", a[i], b[i], mul[i]);
    printf("\nThe division of %.2f and %.2f is : %f\n", a[i], b[i], div[i]);
  }
}
