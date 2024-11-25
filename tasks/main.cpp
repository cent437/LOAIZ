#include "../graph.h"
#include <cstdio>

int main() {
  int **G = NULL, *visited = NULL, size = 0, vertex = 0;
  list **l = NULL;
  puts("Введите размер матрицы смежности:");
  scanf("%d", &size);
  G = generate_adjacency_matrix(size);
  l = create_adjacency_list(G, size);

  puts("Матрица смежности для графа G:");
  print_adjacency_matrix(G, size);

  puts("Список смежности для графа G:");
  print_adjacency_list(l, size);

  visited = (int *)calloc(size, sizeof(int));
  puts("Введите стартовую вершину:");
  scanf("%d", &vertex);

  puts(
      "Обход в ширину по матрице смежности с использованием контейнера queue:");
  bfs_matrix(G, size, visited, vertex - 1);
  for (int i = 0; i < size; i++)
    visited[i] = 0;
  putchar(10);

  puts("Обход в ширину по матрице смежности с использованием класса c_queue:");
  c_bfs(G, size, visited, vertex - 1);
  for (int i = 0; i < size; i++)
    visited[i] = 0;
  putchar(10);

  puts("Обход в ширину по списку смежности:");
  bfs_list(l, size, visited, vertex - 1);
  for (int i = 0; i < size; i++)
    visited[i] = 0;
  putchar(10);

  return 0;
}