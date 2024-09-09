#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
void shell(int *items, int count)
{

  int i, j, gap, k;
  int x, a[5];

  a[0]=9; a[1]=5; a[2]=3; a[3]=2; a[4]=1;

  for(k=0; k < 5; k++) {
    gap = a[k];
    for(i=gap; i < count; ++i) {
      x = items[i];
      for(j=i-gap; (x < items[j]) && (j >= 0); j=j-gap)
        items[j+gap] = items[j];
      items[j+gap] = x;
    }
  }
}
int main()
{
   int n;
   double start, stop;
   srand(time(NULL));
   puts("Enter array size: ");
   scanf("%d", &n);

   int* a = (int*)calloc(n, sizeof(int));
   for (int i = 0; i < (n / 2); i++)
   {
      a[i] = i;
      //printf("%d\t", a[i]);
   }
   for (int i = (n / 2); i > 0; i--)
   {
      a[i] = i;
      //printf("%d\t", a[i]);
   }
   start = clock();
   shell(a, n);
   stop = clock();
   //puts("Sorted array: ");
  //  for (int i = 0; i < n; i++)
  //  {
      // printf("%d\t", a[i]);
   //}
   printf("\nTime of sort (shell): %lf sec", (stop - start) / CLOCKS_PER_SEC);
   free(a);
   getchar();
   return 0;
}
