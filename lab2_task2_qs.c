#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>


void qs(int *items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
  int i, j;
  int x, y;
  i = left; j = right;
  /* выбор компаранда */
  x = items[(left+right)/2];
  
  do {
    while((items[i] < x) && (i < right)) i++;
    while((x < items[j]) && (j > left)) j--;

    if(i <= j) {
      y = items[i];
      items[i] = items[j];
      items[j] = y;
      i++; j--;
    }
  } while(i <= j);

  if(left < j) qs(items, left, j);
  if(i < right) qs(items, i, right);
}

int funccmp (const void *v1, const void* v2)
{
   return (*(int*)v1 - *(int*)v2);
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
   }
   for (int i = (n / 2); i > 0; i--)
   {
      a[i] = i;
   }
   start = clock();
   qsort(a, n, sizeof(int), funccmp);
   stop = clock();

   printf("\nTime of sort (qs): %lf sec", (stop - start) / CLOCKS_PER_SEC);
   free(a);
   getchar();
   return 0;
}
