#include<stdio.h>
#include<omp.h>
#include<unistd.h>

int main(void)
{
  int n, available, produced = 0, consumed = 0;
  printf("How much maximum item do you want to be produced: ");
  scanf("%d", &n);
  #pragma omp parallel shared(produced, consumed)
  {
    #pragma omp master
    {
      for(int i = 0; i< n; i++)
      {
        printf("\nProducer is producing an item ... ");
        sleep(2); // producer takes 2 seconds to produce an item
        printf("\nItem is produced now incrementing the value of produced");
        #pragma omp critical
        {
          produced = produced + 1;
        }
      }
    }
    if(omp_get_thread_num() != 0) //Every thread except the master thread.
    {
      while(consumed != n) // If consumed item is equal to max produced then don't consume and more items
      {
        int isConsumed = 0; // if consumed sleeps for 5 seconds
        #pragma omp critical
        {
          if(produced > 0)
          {
            produced = produced - 1;
            consumed = consumed + 1;
            printf("\nConsumer with tid %d has consumed the item: %d",omp_get_thread_num(), consumed);
            isConsumed = 1;
          }
        }
        if(isConsumed == 1)
        {
          sleep(5); // consumer takes 5 seconds to consume an item
        }
      } 
    }
  }
}
