#include "../graph.h"
#include <cstdio>

int main() {
  int **G = NULL, *visited = NULL, *dist = NULL, size = 0, vertex = 0;
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
  dist = (int *)calloc(size, sizeof(int));
  for (int i = 0; i < size; i++) {
    dist[i] = -1;
    visited[i] = 0;
  }

  puts("Введите стартовую вершину:");
  scanf("%d", &vertex);
  puts("\n===================== Лабораторная работа №7 =====================");

  puts("Обход в глубину по матрице смежности:");
  dfs_matrix(G, vertex - 1, visited, size);
  putchar(10);
  for (int i = 0; i < size; i++)
    visited[i] = 0;

  puts("Обход в глубину по списку смежности:");
  dfs_list(l, vertex - 1, visited, size);
  putchar(10);
  for (int i = 0; i < size; i++)
    visited[i] = 0;

  puts("Обход в глубину без рекурсии :");
  dfs_no_recursive(G, vertex - 1, visited, size);
  for (int i = 0; i < size; i++)
    visited[i] = 0;

  puts("\n===================== Лабораторная работа №8 =====================");
  puts(
      "Обход в ширину по матрице смежности с использованием контейнера queue:");
  bfs_matrix(G, size, visited, vertex - 1);
  putchar(10);
  for (int i = 0; i < size; i++)
    visited[i] = 0;

  puts("Обход в ширину по списку смежности с использованием контейнера queue:");
  bfsd_list(l, vertex - 1, size, dist);
  putchar(10);
  for (int i = 0; i < size; i++)
    dist[i] = -1;

  puts("Обход в ширину с использованием собственного класса очереди:");
  c_bfs(G, size, visited, vertex - 1);
  putchar(10);
  for (int i = 0; i < size; i++)
    visited[i] = 0;

  puts("===================== Лабораторная работа №9 =====================");
  puts("Поиск расстояний по матрице смежности:");
  bfsd_matrix(G, vertex - 1, size, dist);
  for (int i = 0; i < size; i++)
    dist[i] = -1;
  putchar(10);
  puts("Поиск расстояний по списку смежности:");
  bfsd_list(l, vertex - 1, size, dist);

  return 0;
}