#include "../graph.h"
#include <cstdio>

int main() {
  int32_t size, vertex, **G = NULL, *visited = NULL;
  puts("Введите размер матрицы смежности: ");
  scanf("%d", &size);
  G = generate_adjacency_matrix(size);
  list **l = create_adjacency_list(G, size);

  print_adjacency_matrix(G, size);
  putchar('\n');
  print_adjacency_list(l, size);
  visited = (int32_t *)calloc(size, sizeof(int32_t));
  puts("Введите стартовую вершину: ");
  scanf("%d", &vertex);
  for (int i = 0; i < size; i++)
    visited[i] = 0;
  puts("Обход в ширину по матрице смежности через контейнер queue: ");
  bfs_matrix(G, size, visited, vertex - 1);
  putchar('\n');
  puts("Введите стартовую вершину: ");
  scanf("%d", &vertex);

  for (int i = 0; i < size; i++)
    visited[i] = 0;

  puts("Обход в ширину по списку смежности: ");
  bfs_list(l, size, visited, vertex - 1);
  return 0;
}