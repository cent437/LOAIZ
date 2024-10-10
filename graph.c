#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <iso646.h>
/* Печать матрицы смежности. Возвращает количество вершин графа.*/
int32_t print_matrix(int32_t** matrix, int32_t matrix_size);
int main()
{
	int32_t **matrix;
	int32_t *powers;
	int32_t matrix_size = 0;
	int32_t dom;
	int32_t graph_size = 0;
	srand(time(NULL));
	puts("Введите размер матрицы смежности: ");
	scanf("%d", &matrix_size);

	/* Выделение памяти под матрицу смежности и под массив степеней вершин графа */
	for (int32_t i = 0; i < matrix_size; i++) {
		matrix= (int32_t**)calloc(matrix_size, sizeof(int32_t*));
		for (int32_t j = 0; j < matrix_size; j++) {
			matrix[j] = (int32_t*)calloc(matrix_size, sizeof(int32_t));
		}
		
	}						
	powers = (int32_t*)calloc(matrix_size, sizeof(int32_t));
	for (int32_t i = 0; i < (matrix_size / 2); i++) {
		for (int32_t j = 0; j < matrix_size; j++) {
			matrix[i][j] = rand() % 2;  // Создаем связь между двумя вершинами
			matrix[j][i] = matrix[i][j];
			if (i == j) 
				matrix[i][j] = 0; 
			powers[i] += matrix[i][j]; // Подсчитываем степень вершин графа
		}
	}
	putchar('\n');
	graph_size = print_matrix(matrix, matrix_size) / 2;
	printf("Размер графа: %d", graph_size);
	return 0;
}
int32_t print_matrix(int32_t** matrix, int32_t matrix_size)
{
	int32_t size;
	puts("Матрица смежности для графа G:");
	putchar('\t');
	for (int32_t i = 0; i < matrix_size; i++) 
		printf("%d\t", i + 1);
	putchar('\n');

	for (int32_t i = 0; i < matrix_size; i++) {
		printf("%d\t", i + 1);
		for (int32_t j = 0; j < matrix_size; j++) {
			
			printf("%d\t", matrix[i][j]);
			if (matrix[i][j] == 1 and matrix[j][i] == 1) // если есть ребро
				size++;
		}
		putchar('\n');
	}
	return matrix_size;
}