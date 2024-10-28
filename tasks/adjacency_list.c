#include "../graph.h"

int main() {
  int32_t size = 0, vertex = 0;
  puts("Введите размер матриц:");
  scanf("%d", &size);
  if (size <= 0) {
    puts("Графа не существует.");
    return 0;
  }
  int32_t **G1 = generate_adjacency_matrix(size), **G2 = NULL;
  print_adjacency_matrix(G1, size);

  /* Выделение памяти под список смежности */
  list **l = (list **)calloc(size, sizeof(list *));
  for (int32_t i = 0; i < size; i++)
    for (int32_t j = 0; j < size; j++)
      if (G1[i][j] == 1)
        push(l, j + 1, i);
  puts("Список смежности для графа G");
  for (int32_t i = 0; i < size; i++) {
    print_adjacency_list(l, i);
    putchar('\n');
  }
  return 0;
}