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
  puts("---Поиск расстояний по матрице смежности:");
  bfsd_matrix(G, vertex - 1, size, dist);
  printf("\nВектор расстояний от вершины %d до других смежных вершин\n",
         vertex);
  sort(dist, size);
  for (int i = 0; i < size; i++)
    dist[i] = -1;

  puts("\n---Поиск расстояний по списку смежности:");
  bfsd_list(l, vertex - 1, size, dist);
  printf("\nВектор расстояний от вершины %d до других смежных вершин\n",
         vertex);
  sort(dist, size);
  for (int i = 0; i < size; i++)
    dist[i] = 0;

  puts("\n---Поиск расстояний по матрице смежности обходом в глубину:");
  dfsd_matrix(G, vertex - 1, size, dist, visited);
  printf("\nВектор расстояний от вершины %d до других смежных вершин\n",
         vertex);
  // sort(dist, size);
  for (int i = 0; i < size; i++) {
    printf("%d\t", i + 1);
  }
  putchar(10);

  for (int i = 0; i < size; i++) {
    printf("%d\t", dist[i]);
    dist[i] = -1;
  }

  return 0;
}