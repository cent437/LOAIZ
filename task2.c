#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
   int a[10], min = 0, max = 0;
   srand(time(NULL));
   for (int i = 0; i < 10; i++)
   {
      a[i] = rand() % 50 - 25;
      if (a[i] > max)
         max = a[i];
      if (a[i] < min)
          min = a[i];
      printf("%d ", a[i]);
   }
   printf("\n%d - %d = %d", max, min, max - min);
   return 0;
}
