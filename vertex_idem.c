#include "matrix.h"
int main() {
  int32_t size = 0, vertex = 0;
  puts("Введите размер матриц:");
  scanf("%d", &size);
  int32_t **G1 = generate_adjacency_matrix(size), **G2 = NULL;
  print_adjacency_matrix(G1, size);
  puts("Введите номер удаляемой вершины:");
  scanf("%d", &vertex);
  G2 = otozhd(G1, size, vertex);
  print_adjacency_matrix(G2, size - 1);

  return 0;
}