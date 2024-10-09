#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <iso646.h>

int main()
{
	int32_t **a; // Матрица смежности
	int32_t *b; // Массив степеней ребер
	int32_t n = 0; // Размер матрицы смежности
	int32_t dom; // Переменная для доминирующей вершины
	int32_t size = 0;
	puts("Введите размер матрицы смежности: ");
	scanf("%d", &n);
	for (int32_t i = 0; i < n; i++) {
		a = (int32_t**)calloc(n, sizeof(int32_t*));
	}
	for (int32_t i = 0; i < n; i++) {
		a[i] = (int32_t*)calloc(n, sizeof(int32_t));
	}
	b = (int32_t*)calloc(n, sizeof(int32_t));
	srand(time(NULL));
	puts("Матрица смежности для графа G:");
	putchar('\t');
	for (int32_t i = 0; i < n; i++)
		printf("%d\t", i + 1);
	puts("\n");
	
	for (int32_t i = 0; i < n; i++) {
		printf("%d\t", i + 1);
		for (int32_t j = 0; j < n; j++) {
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j]; // Создаем связь между двумя вершинами
			if (i == j) // если элемент матрицы в главной диагонали
				a[i][j] = 0; 
			if (a[i][j] == a[j][i]) // если есть ребро
				size++;
			b[i] += a[i][j]; // Подсчитываем степень вершин графа

			printf("%d\t", a[i][j]);
		}
		
		putchar('\n');
	}
	putchar('\n');
	
		for (int32_t i = 0; i < n; i++)
		{
			if (b[i] > dom)
				dom = b[i];
			printf("deg(v[%d]) = %d", i + 1, b[i]);
			if (b[i] == 0) 
				printf("\tизолированная.");
			else if (b[i] == 1)
				printf("\tконцевая.");
			//else if()
				//puts("Доминирующая");
			putchar('\n');
		}
		printf("Размер графа: %d", size);
	return 0;
}