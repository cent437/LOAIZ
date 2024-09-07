#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MATRIX_SIZE 1000
int main()
{
	clock_t start = 0, stop = 0;
	int i = 0, j = 0, r = 0;
	int a[MATRIX_SIZE][MATRIX_SIZE], b[MATRIX_SIZE][MATRIX_SIZE], c[MATRIX_SIZE][MATRIX_SIZE], elem_c;
	srand(time(NULL));
	start = clock();
	while (i < MATRIX_SIZE)
	{
		while (j < MATRIX_SIZE)
		{
			a[i][j] = rand() % 100 + 1;
			j++;
		}
		i++;
	}
	srand(time(NULL));
	i = 0, j = 0;
	while (i < MATRIX_SIZE)
	{
		while (j < MATRIX_SIZE)
		{
			b[i][j] = rand() % 100 + 1;
			j++;
		}
		i++;
	}
	for (i = 0; i < MATRIX_SIZE; i++)
	{
		for (j = 0; j < MATRIX_SIZE; j++)
		{
			for ( r = 0; r < MATRIX_SIZE; r++)
			{
				elem_c = elem_c + a[i][r] * b[i][r];
				c[i][j] = elem_c;
			}
			
		}
		
	}
	stop = clock();
	printf("Time of matrix multiply: %lf sec.\n", (stop - start) / CLOCKS_PER_SEC);
	return 0;	
}