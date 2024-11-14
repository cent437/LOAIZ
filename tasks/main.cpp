#include "../graph.h"

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
  for (int i = 0; i < size; i++)
    dist[i] = -1;

  puts("Введите стартовую вершину:");
  scanf("%d", &vertex);

  putchar(10);
  puts("Поиск расстояний по матрице смежности с использованим C++ контейнера "
       "queue:");
  bfsd_matrix(G, vertex - 1, size, dist);
  for (int i = 0; i < size; i++)
    dist[i] = -1;
  putchar(10);
  puts("Поиск расстояний по списку смежности:");
  bfsd_list(l, vertex - 1, size, dist);

  return 0;
}