#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <stdint.h>
#include <time.h>

/* Генерация матрицы смежности. */
int32_t **generate_adjacency_matrix(int32_t matrix_size);

/* Печать матрицы инцидентности. */
// int32_t print_incident_matrix(int32_t matrix[][], int32_t matrix_size);

/* Печать матрицы смежности. */
// int32_t print_adjacency_matrix(int32_t matrix[][], int32_t matrix_size);

int main()
{
   int32_t
       adjacency_matrix[4][4] = {0},
       incident_matrix[4][4] = {0},
       *powers,
       matrix_size = 4,
       dom,
       graph_size = 0;
   srand(time(NULL));
   for (int32_t i = 0; i < (matrix_size / 2); i++)
   {
      for (int32_t j = 0; j < matrix_size; j++)
      {
         adjacency_matrix[i][j] = rand() % 2; // Создаем связь между двумя вершинами
         adjacency_matrix[j][i] = adjacency_matrix[i][j];
         if (i == j)
            adjacency_matrix[i][j] = 0;
      }
   }

   // puts("Введите размер матрицы смежности: ");
   // scanf("%d", &matrix_size);
   //  for (int32_t i = 0; i < matrix_size; i++)
   //  {
   //     incident_matrix = (int32_t **)calloc(matrix_size, sizeof(int32_t *));
   //     for (int32_t j = 0; j < matrix_size; j++)
   //        incident_matrix[j] = (int32_t *)calloc(matrix_size, sizeof(int32_t));
   //  }
   // adjacency_matrix = generate_adjacency_matrix(matrix_size);
   // powers = (int32_t *)calloc(matrix_size, sizeof(int32_t));

   /* Создание матрицы инцидентности */
   int k = 0;
   for (int32_t i = 0; i < matrix_size; i++)
   {
      for (int32_t j = 0; j < matrix_size; j++)
      {
         if (i == j)
            continue;
         if (adjacency_matrix[i][j] == 1 and adjacency_matrix[j][i] == 1)
         {
            incident_matrix[i][k] = 1;
            k++;
         }
         else if (adjacency_matrix[i][j] == 0 and adjacency_matrix[j][i] == 0)
         {
            incident_matrix[i][k] = 0;
            k++;
         }
      }
      k xor_eq k;
   }

   puts("Матрица смежности для графа G:");
   putchar(' ');
   putchar(' ');
   for (int32_t i = 0; i < matrix_size; i++)
      printf("%d ", i + 1);
   putchar('\n');
   for (int32_t i = 0; i < matrix_size; i++)
   {
      printf("%d ", i + 1);
      for (int32_t j = 0; j < matrix_size; j++)
         printf("%d ", adjacency_matrix[i][j]);

      putchar('\n');
   }
   puts("Матрица инцидентности для графа G:");
   putchar(' ');
   putchar(' ');
   for (int32_t i = 0; i < matrix_size; i++)
      printf("%d ", i + 1);
   putchar('\n');

   for (int32_t i = 0; i < matrix_size; i++)
   {
      printf("%d ", i + 1);
      for (int32_t j = 0; j < matrix_size; j++)
      {
         printf("%d ", incident_matrix[i][j]);
      }
      putchar('\n');
   }

   // free(adjacency_matrix), free(powers), free(incident_matrix);
   return 0;
}
int32_t print_adjacency_matrix(int32_t matrix[4][4], int32_t matrix_size)
{
   int32_t size;
   puts("Матрица смежности для графа G:");
   putchar(' ');
   putchar(' ');
   for (int32_t i = 0; i < matrix_size; i++)
      printf("%d ", i + 1);
   putchar('\n');

   for (int32_t i = 0; i < matrix_size; i++)
   {
      printf("%d ", i + 1);
      for (int32_t j = 0; j < matrix_size; j++)
      {

         printf("%d ", matrix[i][j]);
         if (matrix[i][j] == 1) // если есть ребро
            size++;
      }
      putchar('\n');
   }
   return size;
}
int32_t print_incident_matrix(int32_t matrix[4][4], int32_t matrix_size)
{
   int32_t size;
   puts("Матрица инцидентности для графа G:");
   putchar(' ');
   putchar(' ');
   for (int32_t i = 0; i < matrix_size; i++)
      printf("%d ", i + 1);
   putchar('\n');

   for (int32_t i = 0; i < matrix_size; i++)
   {
      printf("%d ", i + 1);
      for (int32_t j = 0; j < matrix_size; j++)
      {
         printf("%d ", matrix[i][j]);
         if (matrix[i][j] == 1) // если есть ребро
            size++;
      }
      putchar('\n');
   }
   return size;
}
int32_t **generate_adjacency_matrix(int32_t matrix_size)
{
   int32_t **adjacency_matrix;
   for (int32_t i = 0; i < matrix_size; i++)
   {
      adjacency_matrix = (int32_t **)calloc(matrix_size, sizeof(int32_t *));
      for (int32_t j = 0; j < matrix_size; j++)
         adjacency_matrix[j] = (int32_t *)calloc(matrix_size, sizeof(int32_t));
   }
   for (int32_t i = 0; i < (matrix_size / 2); i++)
   {
      for (int32_t j = 0; j < matrix_size; j++)
      {
         adjacency_matrix[i][j] = rand() % 2; // Создаем связь между двумя вершинами
         adjacency_matrix[j][i] = adjacency_matrix[i][j];
         if (i == j)
            adjacency_matrix[i][j] = 0;
      }
   }
   return adjacency_matrix;
}