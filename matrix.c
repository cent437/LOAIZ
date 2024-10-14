#include "matrix.h"

int32_t **generate_incident_matrix(int32_t matrix_size) {

  int32_t **incident_matrix;

  for (int32_t i = 0; i < matrix_size; i++) {
    incident_matrix = (int32_t **)calloc(matrix_size, sizeof(int32_t *));

    for (int32_t j = 0; j < matrix_size; j++)
      incident_matrix[j] = (int32_t *)calloc(matrix_size, sizeof(int32_t));
  }
  return incident_matrix;
}
int32_t **generate_adjacency_matrix(int32_t matrix_size) {

  int32_t **adjacency_matrix;

  for (int32_t i = 0; i < matrix_size; i++) {
    adjacency_matrix = (int32_t **)calloc(matrix_size, sizeof(int32_t *));

    for (int32_t j = 0; j < matrix_size; j++)
      adjacency_matrix[j] = (int32_t *)calloc(matrix_size, sizeof(int32_t));
  }
  for (int32_t i = 0; i < (matrix_size / 2); i++) {

    for (int32_t j = 0; j < matrix_size; j++) {
      adjacency_matrix[i][j] = rand() % 2;
      adjacency_matrix[j][i] = adjacency_matrix[i][j];
      if (i == j)
        adjacency_matrix[i][j] = 0;
    }
  }
  return adjacency_matrix;
}
int32_t print_adjacency_matrix(int32_t **adjacency_matrix,
                               int32_t matrix_size) {

  int32_t size;

  puts("Матрица смежности для графа G:");
  putchar(' ');
  putchar(' ');

  for (int32_t i = 0; i < matrix_size; i++)
    printf("%d ", i + 1);

  putchar('\n');
  for (int32_t i = 0; i < matrix_size; i++) {

    printf("%d ", i + 1);
    for (int32_t j = 0; j < matrix_size; j++) {

      printf("%d ", adjacency_matrix[i][j]);
      if (adjacency_matrix[i][j] == 1) // если есть ребро
        size++;
    }
    putchar('\n');
  }
  return size;
}

void print_incident_matrix(int32_t **incident_matrix, int32_t matrix_size) {

  puts("Матрица инцидентности для графа G:");
  putchar(' ');
  putchar(' ');

  for (int32_t i = 0; i < matrix_size; i++)
    printf("%d ", i + 1);
  putchar('\n');

  for (int32_t i = 0; i < matrix_size; i++) {
    printf("%d ", i + 1);

    for (int32_t j = 0; j < matrix_size; j++)
      printf("%d ", incident_matrix[i][j]);
    putchar('\n');
  }
}
