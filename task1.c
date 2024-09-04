#include <stdio.h>
#include <stdint.h>
int main()
{
   int32_t a[10] = {5, 12, -1, 6, 16, -3, 51, 95, -8, 12}, min = 0, max = 0;
   int32_t* p_a = a;
   for (int32_t i = 0; i < 10; i++)
   {
      if (*p_a > max)
         max = *p_a;
      if (*p_a < min)
          min = *p_a;
      p_a++;
      printf("%d ", *p_a);
   }
   printf("\n%d - %d = %d", max, min, max - min);
   return 0;
}
