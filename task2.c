#include "matrix.h"

int main() {
  int32_t **adjacency_matrix, **incident_matrix, *powers, matrix_size = 0, dom,
                                                          graph_size = 0;
  srand(time(NULL));
  puts("Введите размер матрицы смежности: ");
  scanf("%d", &matrix_size);

  adjacency_matrix = generate_adjacency_matrix(matrix_size);
  incident_matrix = generate_incident_matrix(matrix_size);
  powers = (int32_t *)calloc(matrix_size, sizeof(int32_t));

  for (int32_t i = 0; i < (matrix_size / 2); i++) {
    for (int32_t j = 0; j < matrix_size; j++) {
      adjacency_matrix[i][j] = rand() % 2;
      adjacency_matrix[j][i] = adjacency_matrix[i][j];
      if (i == j)
        adjacency_matrix[i][j] = 0;
    }
  }

  /* Создание матрицы инцидентности */
  int32_t k = 0;
  for (int32_t i = 0; i < matrix_size; i++) {
    for (int32_t j = 0; j < matrix_size; j++) {
      if (i == j)
        continue;
      if (adjacency_matrix[i][j] == 1 and adjacency_matrix[j][i] == 1) {
        incident_matrix[i][k] = 1;
        k++;
      } else {
        incident_matrix[i][k] = 0;
        k++;
      }
    }
    k xor_eq k;
  }
  print_adjacency_matrix(adjacency_matrix, matrix_size);
  print_incident_matrix(incident_matrix, matrix_size);
  free(adjacency_matrix), free(powers), free(incident_matrix);
  return 0;
}
