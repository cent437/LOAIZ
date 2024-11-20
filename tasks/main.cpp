#include "../graph.h"
#include <cstdio>
#include <cstdlib>
void sort(int *a, int size) {
  int *r = (int *)calloc(size, sizeof(int));
  for (int i = 0; i < size; i++) {
    r[i] = i;
  }
  for (int i = 1; i < size; i++) {
    int k = i;
    while (k > 0 and a[k - 1] > a[k]) {

      a[k - 1] ^= a[k];
      r[k - 1] ^= r[k];

      a[k] ^= a[k - 1];
      r[k] ^= r[k - 1];

      a[k - 1] ^= a[k];
      r[k - 1] ^= r[k];

      k--;
    }
  }
  for (int i = 0; i < size; i++) {
    printf("%d\t", r[i] + 1);
  }
  putchar(10);
  for (int i = 0; i < size; i++) {
    printf("%d\t", a[i]);
  }
}

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
  puts(
      "Обход в ширину по матрице смежности с использованием контейнера queue:");
  bfs_matrix(G, size, visited, vertex - 1);
  putchar(10);
  for (int i = 0; i < size; i++)
    visited[i] = 0;

  puts("Обход в ширину по списку смежности с использованием контейнера queue:");
  bfs_list(l, size, visited, vertex - 1);
  putchar(10);
  for (int i = 0; i < size; i++)
    visited[i] = 0;

  puts("Обход в ширину с использованием собственного класса очереди:");
  c_bfs(G, size, visited, vertex - 1);
  putchar(10);
  for (int i = 0; i < size; i++)
    visited[i] = 0;

  puts("В результате оценки времени обхода в ширину контейнер queue работает "
       "быстрее на больших графах, а класс очереди на малых графах.");

  return 0;
}