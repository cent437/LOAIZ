#include "matrix.h"

int main() {
  int32_t **matrix, *powers, matrix_size = 0, graph_size = 0;
  srand(time(NULL));
  puts("Введите размер матрицы смежности: ");
  scanf("%d", &matrix_size);
  if (matrix_size == 0) {
    puts("Графа не существует.");
    return 0;
  }
  /* Выделение памяти под матрицу смежности и под массив степеней вершин графа
   */
  matrix = generate_adjacency_matrix(matrix_size);
  powers = (int32_t *)calloc(matrix_size, sizeof(int32_t));
  for (int32_t i = 0; i < matrix_size; i++) {
    for (int32_t j = 0; j < matrix_size; j++) {
      powers[i] += matrix[i][j];
    }
  }
  putchar('\n');
  graph_size = print_adjacency_matrix(matrix, matrix_size);
  puts("Степени вершин графа:");
  for (int32_t i = 0; i < matrix_size; i++) {
    printf("deg[%d] = %d", i + 1, powers[i]);
    if (powers[i] == 0)
      printf(" изолированная.");
    else if (powers[i] == 1)
      printf(" концевая.");
    putchar('\n');
  }
  for (int32_t i = 0; i < matrix_size; i++) {
    if (powers[i] == matrix_size)
      printf("Вершина %d - доминирующая.\n", i + 1);
  }
  printf("Размер графа: %d", graph_size);
  free(matrix), free(powers);

  return 0;
}
