#include "../graph.h"
#include <cstdint>
#include <cstdio>

int32_t main() {

  int32_t size, vertex, **G = NULL, *visited = NULL;
  puts("Введите размер матрицы смежности: ");
  scanf("%d", &size);

  G = generate_adjacency_matrix(size);
  visited = (int32_t *)calloc(size, sizeof(int32_t));
  print_adjacency_matrix(G, size);
  list **l = create_adjacency_list(G, size);

  /* Печать списков смежности */
  print_adjacency_list(l, size);

  puts("Введите номер стартовой вершины: ");
  scanf("%d", &vertex);
  putchar('\n');
  for (int32_t i = 0; i < size; i++)
    visited[i] = 0;

  puts("Пройденный маршрут:");

  puts("Обход в глубину по матрице смежности:");
  dfs_matrix(G, vertex - 1, visited, size);
  for (int32_t i = 0; i < size; i++)
    visited[i] = 0;
  putchar(10);
  puts("Обход в глубину по списку смежности:");
  dfs_list(l, vertex - 1, visited, size);
  for (int32_t i = 0; i < size; i++)
    visited[i] = 0;
  putchar(10);
  puts("Обход в глубину без рекурсии:");
  dfs_matrix_no_recursive(G, vertex - 1, visited, size);
  putchar(10);
  return 0;
}