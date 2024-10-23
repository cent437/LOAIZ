#include "matrix.h"

int main() {
  int32_t size = 0;
  puts("Введите размер графов:");
  scanf("%d", &size);
  int32_t **G1 = generate_adjacency_matrix(size),
          **G2 = generate_adjacency_matrix(size - 1);
  G2 = otozhd(G1, size, 4);
  print_adjacency_matrix(G1, size);
  print_adjacency_matrix(G2, size - 1);

  return 0;
}