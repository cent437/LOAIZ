#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

int main()
{
   int32_t n;
   printf("Enter the array size: ");
   scanf("%d", &n);
   if (n >= INT_MAX)
   {
      puts("Error. Memory overflow.");
      return 0;
   }
   
   int32_t* a = (int32_t*) malloc(n * sizeof(int32_t));
   
   int32_t min = 0, max = 0;
   srand(time(NULL));
   for (int i = 0; i < n; i++)
   {
      a[i] = rand() % 50 - 25;
      if (a[i] > max)
         max = a[i];
      if (a[i] < min)
          min = a[i];
      printf("%d ", a[i]);
   }
   printf("\n%d - %d = %d", max, min, max - min);
   free(a);
   return 0;
}