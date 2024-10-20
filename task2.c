#include "matrix.h"

int main() {
  int32_t **adjacency_matrix, **incident_matrix, *powers, matrix_size = 0,
                                                          graph_size = 0;
  srand(time(NULL));
  puts("Введите размер матрицы смежности: ");
  scanf("%d", &matrix_size);
  if (matrix_size == 0) {
    puts("Графа не существует.");
    return 0;
  }
  adjacency_matrix = generate_adjacency_matrix(matrix_size);

  powers = (int32_t *)calloc(matrix_size, sizeof(int32_t));

  graph_size = print_adjacency_matrix(adjacency_matrix, matrix_size);

  incident_matrix = generate_incident_matrix(matrix_size, graph_size);

  /* Создание матрицы инцидентности */
  int32_t k = 0;
  for (int32_t i = 0; i < matrix_size; i++) {
    for (int32_t j = i + 1; j < matrix_size; j++) {
      if (adjacency_matrix[i][j] == 1) {
        incident_matrix[i][k] = 1;
        incident_matrix[j][k] = 1;
        k++;
      } else
        incident_matrix[i][j] = 0;
    }
  }
  for (int32_t i = 0; i < matrix_size; i++)
    for (int32_t j = 0; j < matrix_size; j++)
      powers[i] += incident_matrix[i][j];

  print_incident_matrix(incident_matrix, matrix_size, graph_size);

  puts("Степени вершин графа:");
  for (int32_t i = 0; i < matrix_size; i++) {
    printf("deg[%d] = %d", i + 1, powers[i]);
    if (powers[i] == 0)
      printf(" изолированная.");
    else if (powers[i] == 1)
      printf(" концевая.");
    putchar('\n');
  }
  for (int32_t i = 0; i < matrix_size; i++)
    if (powers[i] == matrix_size)
      printf("Вершина %d - доминирующая.\n", i + 1);

  printf("Размер графа: %d", graph_size);
  free(adjacency_matrix), free(incident_matrix), free(powers);
  return 0;
}
