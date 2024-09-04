#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int main()
{
   int16_t matrix[3][3] = {0};
   int16_t sum_rows[3] = {0}, sum_cols[3] = {0};
   srand(time(NULL));
   for (int32_t i = 0; i < 3; i++)
   {
      for (int32_t j = 0; j < 3; j++)
      {
         matrix[i][j] = rand() % 10 + 5;
         sum_rows[i] += matrix[i][j];
         sum_cols[i] += matrix[j][i];
         printf("%d\t", matrix[i][j]);
      }
      puts("\n");
   }
   puts("\nSumm of rows: ");
   for (int32_t i = 0; i < 3; i++)
      printf("%d ", sum_rows[i]);
   puts("\nSumm of cols: ");
   for (int32_t i = 0; i < 3; i++)
      printf("%d ", sum_cols[i]);
   
   return 0;
}