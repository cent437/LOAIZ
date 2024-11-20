#include "../graph.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
int main(int argc, char *argv[]) {
  int **G = NULL, *visited = NULL, *dist = NULL, size = 0, vertex = 0;
  list **l = NULL;
  puts("Введите размер матрицы смежности:");
  scanf("%d", &size);
  if (argc == 1) {
    G = generate_adjacency_matrix_orient(size);
    l = create_adjacency_list(G, size);
  } else if (argc > 1) {
    for (int i = 0; i < argc; i++) {
      if (strcmp(argv[i], "-weight") == 0) {
        G = generate_adjacency_matrix_weight(size);
        l = create_adjacency_list(G, size);
      }
      if (strcmp(argv[i], "-orient") == 0) {
        G = generate_adjacency_matrix_orient(size);
        l = create_adjacency_list(G, size);
      }
      if (strcmp(argv[i], "-orient_weight") == 0) {
        G = generate_adjacency_matrix_orient_weight(size);
        l = create_adjacency_list(G, size);
      }
    }
  }
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
  puts("Поиск расстояний по матрице смежности:");
  bfsd_matrix(G, vertex - 1, size, dist);

  printf("\nВектор расстояний от вершины %d до других смежных вершин:\n",
         vertex);
  for (int i = 0; i < size; i++)
    printf("%d\t", i + 1);
  putchar(10);
  for (int i = 0; i < size; i++) {
    printf("%d\t", dist[i]);
    dist[i] = -1;
  }
  putchar(10);
  puts("Поиск расстояний по списку смежности взвешенного графа:");
  bfsd_list(l, vertex - 1, size, dist);
  printf("\nВектор расстояний от вершины %d до других смежных вершин:\n",
         vertex);

  for (int i = 0; i < size; i++)
    printf("%d\t", i + 1);
  putchar(10);
  for (int i = 0; i < size; i++) {
    printf("%d\t", dist[i]);
    dist[i] = -1;
  }

  putchar(10);
  if (argc > 1) {
    for (int i = 0; i < argc; i++) {
      if (strcmp(argv[i], "-weight") == 0 ||
          strcmp(argv[i], "-orient_weight") == 0)
        diameter_radius(G, size);
    }
  }

  return 0;
}