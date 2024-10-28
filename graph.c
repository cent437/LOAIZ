#include "graph.h"

int32_t **generate_incident_matrix(int32_t rows, int32_t cols) {
  int32_t **incident_matrix;
  incident_matrix = (int32_t **)calloc(rows, sizeof(int32_t *));
  for (int32_t i = 0; i < rows; i++)
    incident_matrix[i] = (int32_t *)calloc(cols, sizeof(int32_t));
  if (incident_matrix == NULL) {
    puts("Ошибка выделения памяти.");
    exit(1);
  }
  return incident_matrix;
}
int32_t **generate_adjacency_matrix(int32_t matrix_size) {
  int32_t **adjacency_matrix =
      (int32_t **)calloc(matrix_size, sizeof(int32_t *));
  for (int32_t i = 0; i < matrix_size; i++)
    adjacency_matrix[i] = (int32_t *)calloc(matrix_size, sizeof(int32_t));
  for (int32_t i = 0; i < (matrix_size / 2); i++) {
    for (int32_t j = 0; j < matrix_size; j++) {
      adjacency_matrix[i][j] = rand() % 2;
      adjacency_matrix[j][i] = adjacency_matrix[i][j];
    }
    adjacency_matrix[i][i] = 0;
  }
  return adjacency_matrix;
}

int32_t print_adjacency_matrix(int32_t **adjacency_matrix,
                               int32_t matrix_size) {

  int32_t size = 0;
  int32_t loops = 0;
  puts("Матрица смежности для графа G:");
  putchar(' ');
  putchar(' ');

  for (int32_t i = 0; i < matrix_size; i++)
    printf("%d ", i + 1);

  putchar('\n');
  for (int32_t i = 0; i < matrix_size; i++) {

    printf("%d ", i + 1);

    for (int32_t j = 0; j < matrix_size; j++) {
      printf("%d ", adjacency_matrix[i][j]);
      if (adjacency_matrix[i][j] == 1 &&
          adjacency_matrix[j][i] == 1) // если есть ребро
        size++;
    }
    loops += adjacency_matrix[i][i];
    putchar('\n');
  }
  size /= 2;
  size += loops;
  return size;
}
int32_t **otozhd(int32_t **G, int32_t size, int32_t V) {
  int32_t **G_new = NULL;
  if ((V + 1) > size) {
    printf("Вершины %d не существует.\n", V);
    exit(1);
  }
  G_new = generate_adjacency_matrix(size - 1);
  for (int32_t i = 0; i < size; i++) {
    for (int32_t j = 0; j < size; j++) {
      /* Если удаляемая вершина - левый верхний
      или правый нижний угол матрицы смежности */
      if (i == V and j == V) {
        for (i = 0; i < (size - 1); i++) {
          for (j = 0; j < (size - 1); j++)
            G_new[i][j] = G[i + 1][j + 1];
        }
        return G_new;
      }

      if (i < V and j < V)
        G_new[i][j] = G[i][j];

      if (i > V and j > V)
        G_new[i - 1][j] = G[i][j];

      if (i < V and j > V)
        G_new[i][j - 1] = G[i][j];

      if (i > V and j < V)
        G_new[i - 1][j] = G[i][j];
    }
  }
  return G_new;
}
void print_incident_matrix(int32_t **incident_matrix, int32_t rows,
                           int32_t cols) {
  puts("Матрица инцидентности для графа G:");
  putchar(' ');
  putchar(' ');

  for (int32_t i = 0; i < cols; i++)
    printf("%c ", i + 0x61);
  putchar('\n');

  for (int32_t i = 0; i < rows; i++) {
    printf("%d ", i + 1);
    for (int32_t j = 0; j < cols; j++) {
      printf("%d ", incident_matrix[i][j]);
    }
    putchar('\n');
  }
}

list *create_node(int32_t data) {
  list *p = NULL;
  p = (list *)malloc(sizeof(list));
  if (p == NULL) {
    puts("Error");
    exit(1);
  }
  p->index = data;
  p->next = NULL;
  return p;
}

void push(list **lists_pointer, int32_t data, int32_t head_index) {
  list *p = NULL;
  p = create_node(data);
  /* Если списка нет, то добавляем элемент в голову */
  if (lists_pointer[head_index] == NULL and p != NULL)
    lists_pointer[head_index] = p;

  /* Если список есть, то добавляем элемент в начало списка */
  else if (lists_pointer[head_index] != NULL and p != NULL) {
    lists_pointer[head_index]->prev = p;
    p->next = lists_pointer[head_index];
    lists_pointer[head_index] = p;
  }
}

void print_adjacency_list(list **lists_pointer, int32_t head_index) {
  list *p = lists_pointer[head_index];
  if (lists_pointer == NULL)
    puts("List is empty");
  printf("%d:\t", head_index + 1);
  while (p) {
    printf("%d\t", p->index);
    p = p->next;
  }
  return;
}