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
int funccmp (const void *v1, const void* v2)
{
   return (*(int*)v1 - *(int*)v2);
}
int main()
{
   int n;
   double start, stop;
   srand(time(NULL));
   n = 1;
   for (int i = 0; i < 4; i++)
   {
      n *= 100;
      int* a = (int*)calloc(n, sizeof(int));
      FILE* t_measure = fopen("time.txt", "w+");
      switch (i)
      {
      case 0:
         for (int i = 0; i < n; i++)
         {
            a[i] = rand() % 50;
         }
         start = clock();
         shell(a, n);
         stop = clock();
         fprintf(t_measure, "%d) Time of shell (random): %lf\n",i , (stop - start )/ CLOCKS_PER_SEC);
         
         for (int i = 0; i < n; i++)
         {
            a[i] = rand() % 50;
         }
         start = 0, stop = 0;
         
         start = clock();
         qs(a, 0, n - 1);
         stop = clock();
         fprintf(t_measure, "%d) Time of qs (random): %lf\n", i, (stop - start )/ CLOCKS_PER_SEC);
         
         for (int i = 0; i < n; i++)
         {
            a[i] = rand() % 50;
         }
         start = 0, stop = 0;
         
         start = clock();
         qsort(a, n, sizeof(int), funccmp);
         stop = clock();
         fprintf(t_measure, "%d) Time of qsort() (random): %lf\n", i, (stop - start )/ CLOCKS_PER_SEC);
         
         break;
      case 1:
         
         for (int i = 0; i < n; i++)
         {
            a[i] = i;
         }
         start = clock();
         shell(a, n);
         stop = clock();
         fprintf(t_measure, "%d) Time of shell (inc): %lf\n",i , (stop - start )/ CLOCKS_PER_SEC);
         
         for (int i = 0; i < n; i++)
         {
            a[i] = i;
         }
         start = 0, stop = 0;
         
         start = clock();
         qs(a, 0, n - 1);
         stop = clock();
         fprintf(t_measure, "%d) Time of qs (inc): %lf\n", i, (stop - start )/ CLOCKS_PER_SEC);
         
         for (int i = n; i > 0; i--)
         {
            a[i] = i;
         }
         start = 0, stop = 0;
         
         start = clock();
         qsort(a, n, sizeof(int), funccmp);
         stop = clock();
         fprintf(t_measure, "%d) Time of qsort() (inc): %lf\n", i, (stop - start )/ CLOCKS_PER_SEC);
         break;   
      case 2:
         
         for (int i = n; i > 0; i--)
         {
            a[i] = i;
         }
         start = clock();
         shell(a, n);
         stop = clock();
         fprintf(t_measure, "%d) Time of shell (decr): %lf\n",i , (stop - start )/ CLOCKS_PER_SEC);
         
         for (int i = n; i > 0; i--)
         {
            a[i] = i;
         }
         start = 0, stop = 0;
         start = clock();
         qs(a, 0, n - 1);
         stop = clock();
         fprintf(t_measure, "%d) Time of qs (decr): %lf\n", i, (stop - start )/ CLOCKS_PER_SEC);
         
         for (int i = n; i > 0; i--)
         {
            a[i] = i;
         }
         start = 0, stop = 0;
         
         start = clock();
         qsort(a, n, sizeof(int), funccmp);
         stop = clock();
         fprintf(t_measure, "%d) Time of qsort() (decr): %lf\n", i, (stop - start )/ CLOCKS_PER_SEC);
         break;
      case 3:
         
         for (int i = 0; i < (n / 2); i++)
         {
            a[i] = i;
         }
         start = clock();
         shell(a, n);
         stop = clock();
         fprintf(t_measure, "%d) Time of shell (inc | decr): %lf\n",i , (stop - start )/ CLOCKS_PER_SEC);
         
         for (int i = 0; i < (n / 2); i++)
         {
            a[i] = i;
         }
         start = 0, stop = 0;
         start = clock();
         qs(a, 0, n - 1);
         stop = clock();
         fprintf(t_measure, "%d) Time of qs (inc | decr): %lf\n", i, (stop - start )/ CLOCKS_PER_SEC);
         
         for (int i = 0; i < (n / 2); i++)
         {
            a[i] = i;
         }
         start = 0, stop = 0;
         
         start = clock();
         qsort(a, n, sizeof(int), funccmp);
         stop = clock();
         fprintf(t_measure, "%d) Time of qsort() (inc | decr): %lf\n", i, (stop - start )/ CLOCKS_PER_SEC);
         break;
      }
      fclose(t_measure);
      free(a);
   }
   puts("end.");
   getchar();
   return 0;
}
