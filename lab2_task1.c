#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	double start = 0, stop = 0;
	int i = 0, j = 0, r = 0;
	int a[1000][1000], b[1000][1000], c[1000][1000], elem_c;
	srand(time(NULL));
	start = clock();
	while (i < 1000)
	{
		while (j < 1000)
		{
			a[i][j] = rand() % 100 + 1;
			j++;
		}
		i++;
	}
	srand(time(NULL));
	i = 0, j = 0;
	while (i < 1000)
	{
		while (j < 1000)
		{
			b[i][j] = rand() % 100 + 1;
			j++;
		}
		i++;
	}
	for (i = 0; i < 1000; i++)
	{
		for (j = 0; j < 1000; j++)
		{
			for ( r = 0; r < 1000; r++)
			{
				elem_c = elem_c + a[i][r] * b[i][r];
				c[i][j] = elem_c;
			}
			
		}
		
	}
	stop = clock();
	printf("Time of matrix multiply: %lf sec.\n", (stop - start) / 1000);
	return 0;	
}