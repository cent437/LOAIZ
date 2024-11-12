#include "../graph.h"

void dfs_list(list **l, int32_t start, int32_t *visited, int32_t size) {
  list *head = l[start];
  visited[start] = 1;
  printf("%d ", start + 1);
  while (head != NULL) {
    if (visited[head->index - 1] == 0) {
      dfs_list(l, head->index - 1, visited, size);
    }
    head = head->next;
  }
}

void dfs_matrix(int32_t **G, int32_t start, int32_t *visited, int32_t size) {
  visited[start] = 1;
  printf("%d ", start + 1);
  for (int i = 0; i < size; i++) {
    if (G[start][i] == 1 and visited[i] == 0) {
      dfs_matrix(G, i, visited, size);
    }
  }
  return;
}

int32_t main() {

  int32_t size, vertex, **G = NULL, *visited = NULL;
  puts("Введите размер матрицы смежности: ");
  scanf("%d", &size);

  G = generate_adjacency_matrix(size);
  visited = calloc(size, sizeof(int32_t));
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

  puts("Обход в глубину по списку смежности:");
  dfs_list(l, vertex - 1, visited, size);

  return 0;
}