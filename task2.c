#include "matrix.h"
#include <iso646.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
  int32_t **adjacency_matrix, **incident_matrix, powers, matrix_size = 0, dom,
                                                         graph_size = 0;

  srand(time(NULL));
  puts("Введите размер матрицы смежности: ");
  scanf("%d", &matrix_size);
  if (matrix_size == 0) {
    puts("Графа не существует.");
    return 0;
  }
  adjacency_matrix = generate_adjacency_matrix(matrix_size);
  incident_matrix = generate_incident_matrix(matrix_size);
  
  /* Создание матрицы инцидентности */
  int32_t k = 0;
  for (int32_t i = 0; i < matrix_size; i++) {
    for (int32_t j = 0; j < matrix_size; j++) {
      if (i == j)
        continue;
      powers += incident_matrix[i][k];
      if (adjacency_matrix[i][j] == 1 and adjacency_matrix[j][i] == 1) {
        incident_matrix[i][k] = 1;
        graph_size += incident_matrix[i][k];

        k++;
      } else {
        incident_matrix[i][k] = 0;
        graph_size += incident_matrix[i][k];
        k++;
      }
    }
    k xor_eq k;
    if (powers == (graph_size - 1) and adjacency_matrix[i][i] == 0 or
        (powers == graph_size))
      printf("Вершина %d доминантная.\n", i + 1);
    else if (powers == 1 and adjacency_matrix[i][i] == 0)
      printf("Вершина %d концевая.\n", i + 1);
    else if (powers == 1 and adjacency_matrix[i][i] == 1)
      printf("Вершина %d изолированная.\n", i + 1);
  }
  graph_size = graph_size / 2;

  print_adjacency_matrix(adjacency_matrix, matrix_size);
  print_incident_matrix(incident_matrix, matrix_size);
  printf("Размер графа: %d", graph_size);
  free(adjacency_matrix), free(incident_matrix);
  return 0;
}
