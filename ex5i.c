#include<stdio.h>
#include<omp.h>

int main(void)
{
  int sum = 0, n;
  
  printf("Enter how many values you want to insert in the array: ");
  scanf("%d",&n);
  
  int arr[n];
  
  printf("\nEnter the values in the array: \n");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  
  #pragma omp parallel for schedule(guided, 2) firstprivate(sum)
  for(int i = 0; i < 2; i++)
  {
    if(i == 0)
    {
      for(int j=0; j<n; j++)
      {
        if(arr[j]%2 == 0)
        {
          sum = sum + arr[j];
        }
      }
      printf("\nSum of Even Numbers: %d",sum);
    }
    else{
      for(int j=0; j<n; j++)
      {
        if(arr[j]%2 != 0)
        {
          sum = sum + arr[j];
        }
      }
      printf("\nSum of Odd Numbers: %d",sum);
    }
  }
}
