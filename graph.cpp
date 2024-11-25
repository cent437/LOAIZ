#include "graph.h"
#include <stdint.h>
#include <stdio.h>
int32_t **generate_adjacency_matrix(int32_t matrix_size) {
  srand(time(NULL));
  if (matrix_size <= 0) {
    return NULL;
  }
  int32_t **adjacency_matrix =
      (int32_t **)calloc(matrix_size, sizeof(int32_t *));
  for (int32_t i = 0; i < matrix_size; i++) {
    adjacency_matrix[i] = (int32_t *)calloc(matrix_size, sizeof(int32_t));
    adjacency_matrix[matrix_size] = NULL;
  }
  for (int32_t i = 0; i < (matrix_size / 2); i++) {
    for (int32_t j = 0; j < matrix_size; j++) {
      adjacency_matrix[i][j] = rand() % 2;
      adjacency_matrix[j][i] = adjacency_matrix[i][j];
    }
    adjacency_matrix[i][i] = 0;
  }
  return adjacency_matrix;
}
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

void print_adjacency_matrix(int32_t **adjacency_matrix, int32_t matrix_size) {
  putchar(' ');
  putchar(' ');
  for (int32_t i = 0; i < matrix_size; i++)
    printf("%d ", i + 1);
  putchar('\n');
  for (int32_t i = 0; i < matrix_size; i++) {
    printf("%d ", i + 1);
    for (int32_t j = 0; j < matrix_size; j++) {
      printf("%d ", adjacency_matrix[i][j]);
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
  list *tail = NULL;
  p = create_node(data);
  /* Если списка нет, то добавляем элемент в голову */
  if (lists_pointer[head_index] == NULL and p != NULL)
    lists_pointer[head_index] = p;

  /* Если список есть, то добавляем вершину в конец списка */
  else if (lists_pointer[head_index] != NULL and p != NULL) {
    tail = lists_pointer[head_index];

    /* Цикл перехода в конец списка */
    while (tail->next != NULL) {
      tail = tail->next;
    }

    /* Добавление вершины в конец списка */
    tail->next = p;
    p->prev = tail;
    tail = p;
  }
}
list **create_adjacency_list(int32_t **G, int32_t size) {

  list **l = (list **)calloc(size, sizeof(list *));
  for (int32_t i = 0; i < size; i++)
    for (int32_t j = 0; j < size; j++)
      if (G[i][j] == 1)
        push(l, j + 1, i);
  puts("Список смежности для графа G");

  return l;
}

void print_adjacency_list(list **lists_pointer, int32_t size) {
  int32_t head_index = 0;
  list **head = lists_pointer;
  list *p = lists_pointer[head_index];
  if (lists_pointer == NULL) {
    puts("List is empty");
    return;
  }
  for (int32_t i = 0; i < size; i++) {
    printf("%d:\t", head_index + 1);
    while (p) {
      printf("%d\t", p->index);
      p = p->next;
    }
    putchar('\n');
    head_index++;
    p = lists_pointer[head_index];
  }
}

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
void dfs_matrix_no_recursive(int32_t **G, int32_t start, int32_t *visited,
                             int32_t size) {

  visited[start] = 1;
  int32_t sum = 0;
  // printf("%d ", start + 1);
  while (sum != size) {
    for (int i = 0; i < size; i++) {
      if (G[start][i] == 1 and visited[i] == 0) {
        start = i;
        // i = 0;
        sum++;
        break;
        // dfs_matrix(G, i, visited, size);
      }
    }
    printf("%d ", start + 1);
    visited[start] = 1;
  }

  return;
}
