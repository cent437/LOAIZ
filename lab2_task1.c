#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 10000
#define Y 10000
int main()
{
	double start = 0, stop = 0;
	int i = 0, j = 0, r = 0;
	int** a = (int**)calloc(X * Y, sizeof(int*)); // O(1)
	int** b = (int**)calloc(X * Y, sizeof(int*)); // O(1)
	int** c = (int**)calloc(X * Y, sizeof(int*)); // O(1)
	int elem_c = 0;
	srand(time(NULL));
	for (i = 0; i < Y; i++) // O(N)
	{
		a[i] = (int*)calloc(Y, sizeof(int)); // O(1)
		b[i] = (int*)calloc(Y, sizeof(int)); // O(1)
		c[i] = (int*)calloc(Y, sizeof(int)); // O(1)
	}
	i = 0, j = 0;
	puts("Multiply...");
	start = clock();
	for (i = 0; i < X; i++)	// O(N^3)
	{
		for (j = 0; j < Y; j++)
		{
			a[i][j] = rand() % 100;
			b[i][j] = rand() % 100;
			for ( r = 0; r < Y; r++)
			{
				elem_c = elem_c + a[i][r] * b[i][r];
				c[i][j] = elem_c;
			}
		}
	}
	stop = clock();
	printf("Time of matrix %dx%d multiply : %lf sec.\n", X, Y, (stop - start) / CLOCKS_PER_SEC);
	free(a);	// O(1)
	free(b);	// O(1)
	free(c);	// O(1)
	getchar();
	return 0;	
}