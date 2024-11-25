#include "graph.h"
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
c_stack::stack *c_stack::create_stack_node(int data) {
  stack *p = NULL;
  p = (stack *)malloc(sizeof(stack));
  if (p == NULL) {
    puts("Error");
    exit(1);
  }
  p->data = data;
  p->next = NULL;
  return p;
}
void c_stack::push(int data) {
  stack *p = NULL;
  p = create_stack_node(data);
  if (this->head == NULL and
      p != NULL) // Если списка нет, то добавляем элемент в голову и в хвост
  {
    this->head = p;
    this->tail = p;
  } else if (this->head != NULL and
             p != NULL) // Если список есть, то добавляем элемент в конец списка
  {
    this->tail->next = p;
    this->tail = p;
  }
  return;
}

void c_stack::pop() {
  stack *p = this->head;
  stack *prv;
  if (this->head == NULL)
    return;
  while (p != this->tail) // Проход до последнего элемента списка с
                          // отслеживанием предпоследнего
  {
    prv = p;
    p = p->next;
  }

  if (this->head == this->tail) // Проверка на то, что в списке 1 элемент
  {
    this->head = NULL; // Обнуляем голову и хвост
    this->tail = NULL;
    return;
  }
  free(p);
  prv->next = NULL;
  this->tail = prv;
  return;
}

c_queue::node *c_queue::create_node(int data) {
  c_queue::node *p = NULL;
  p = (c_queue::node *)malloc(sizeof(c_queue::node));
  if (p == NULL) {
    puts("Error");
    exit(1);
  }
  p->data = data;

  p->next = NULL;
  return p;
}
void c_queue::push(int data) {
  c_queue::node *p = NULL;
  p = create_node(data);
  if (this->head == NULL && p != NULL) {
    this->head = p;
    this->tail = p;
  } else if (this->head != NULL && p != NULL) {
    this->head->prev = p;
    p->next = head;
    this->head = p;
  }
  return;
}
void c_queue::pop() {
  c_queue::node *p = this->head;
  c_queue::node *prv;
  if (this->head == NULL) // Если список пуст, возвращаемся
    return;
  while (p != this->tail) // Проход до последнего элемента списка с
                          // отслеживанием предпоследнего
  {
    prv = p;
    p = p->next;
  }

  if (this->head == this->tail) // Проверка на то, что в списке 1 элемент
  {
    this->head = NULL; // Обнуляем голову и хвост
    this->tail = NULL;
    return;
  }
  free(p);
  prv->next = NULL;
  this->tail = prv;
  return;
}

int32_t **generate_adjacency_matrix(int32_t matrix_size) {
  // srand(time(NULL));
  if (matrix_size <= 0) {
    return NULL;
  }
  int32_t **adjacency_matrix =
      (int32_t **)calloc(matrix_size, sizeof(int32_t *));
  for (int32_t i = 0; i < matrix_size; i++) {
    adjacency_matrix[i] = (int32_t *)calloc(matrix_size, sizeof(int32_t));
    adjacency_matrix[matrix_size] = NULL;
  }
  for (int32_t i = 0; i < matrix_size; i++) {
    for (int32_t j = i; j < matrix_size; j++) {
      adjacency_matrix[i][j] = rand() % 2;
      adjacency_matrix[j][i] = adjacency_matrix[i][j];
    }
    adjacency_matrix[i][i] = 0;
  }
  return adjacency_matrix;
}

int32_t **generate_adjacency_matrix_weight(int32_t matrix_size) {
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
  for (int32_t i = 0; i < matrix_size; i++) {
    for (int32_t j = i; j < matrix_size; j++) {
      adjacency_matrix[i][j] = rand() % 20;
      adjacency_matrix[j][i] = adjacency_matrix[i][j];
    }
    adjacency_matrix[i][i] = 0;
  }
  return adjacency_matrix;
}

int32_t **generate_adjacency_matrix_orient(int32_t matrix_size) {
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
  for (int32_t i = 0; i < matrix_size; i++) {
    for (int32_t j = 0; j < matrix_size; j++) {
      adjacency_matrix[i][j] = rand() % 2;
    }
    adjacency_matrix[i][i] = 0;
  }
  return adjacency_matrix;
}

int32_t **generate_adjacency_matrix_orient_weight(int32_t matrix_size) {
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
  for (int32_t i = 0; i < matrix_size; i++) {
    for (int32_t j = 0; j < matrix_size; j++) {
      adjacency_matrix[i][j] = rand() % 20;
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
  printf("       ");
  for (int32_t i = 0; i < matrix_size; i++)
    printf("%-4d", i + 1);
  putchar('\n');
  for (int32_t i = 0; i < matrix_size; i++) {
    printf("%d      ", i + 1);
    for (int32_t j = 0; j < matrix_size; j++) {
      printf("%-4d", adjacency_matrix[i][j]);
    }
    putchar('\n');
  }
}

list *create_node(int32_t data, int32_t weight) {
  list *p = NULL;
  p = (list *)malloc(sizeof(list));
  if (p == NULL) {
    puts("Error");
    exit(1);
  }
  p->index = data;
  p->weight = weight;
  p->next = NULL;
  return p;
}

void push(list **lists_pointer, int32_t data, int32_t weight,
          int32_t head_index) {
  list *p = NULL;
  list *tail = NULL;
  p = create_node(data, weight);
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
      if (G[i][j] >= 1)
        push(l, j + 1, G[i][j], i);

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

void dfs_matrix(int32_t **G, int32_t start, int32_t *visited, int32_t size) {
  visited[start] = 1;
  printf("%d ", start + 1);
  for (int i = 0; i < size; i++) {
    if (G[start][i] == 1 and visited[i] == 0) {
      dfs_matrix(G, i, visited, size);
    }
  }
}
void dfs_no_recursive(int32_t **G, int32_t start, int32_t *visited,
                      int32_t size) {

  visited[start] = 1;
  int sum_visited = 0;
  printf("%d ", start + 1);
  while (sum_visited < size) {
    visited[start] = 1;
    for (int i = 0; i < size; i++) {
      if (G[start][i] == 1 and visited[i] == 0) {
        start = i;
        printf("%d ", start + 1);
      }
      sum_visited += visited[i];
    }
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

void bfs_matrix(int32_t **G, int32_t size, int32_t *visited, int32_t v) {
  double start = clock(), stop = 0;
  std::queue<int32_t> q;
  q.push(v);
  visited[v] = 1;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    printf("%d ", v + 1);
    for (int i = 0; i < size; i++) {
      if (G[v][i] == 1 and visited[i] == 0) {
        q.push(i);
        visited[i] = 1;
      }
    }
  }
  stop = clock();
  printf("\nВремя обхода графа: %lf", (stop - start) / 1000);
}
void bfs_list(list **l, int32_t size, int32_t *visited, int32_t v) {
  c_queue q;
  list *prv = NULL;
  q.push(v);
  visited[v] = 1;
  /* Переход в стартовый список смежных вершин. */
  list *head = l[v];
  while (q.head != NULL) {
    v = q.tail->data;
    q.pop();
    printf("%d ", v + 1);
    while (head != NULL) {
      if (visited[head->index - 1] == 0) {
        q.push(head->index - 1);
        visited[head->index - 1] = 1;
      }
      /* Отслеживание предыдущего элемента для перехода в другой список смежных
       * вершин. */
      prv = head;
      head = head->next;
    }
    /* Переход в другой список смежных вершин. */
    head = l[prv->index - 1];
  }
}

void c_bfs(int32_t **G, int32_t size, int32_t *visited, int32_t v) {
  double start = 0, stop = 0;
  c_queue q;
  start = clock();
  q.push(v);
  visited[v] = 1;
  while (q.head != NULL && q.tail != NULL) {
    v = q.tail->data; // q.front();
    q.pop();
    printf("%d ", v + 1);
    for (int i = 0; i < size; i++) {
      if (G[v][i] == 1 && visited[i] == 0) {
        q.push(i);
        visited[i] = 1;
      }
    }
  }
  stop = clock();
  printf("\nВремя обхода графа: %lf", (stop - start) / 1000);
}


void bfsd_matrix(int32_t **G, int32_t v, int32_t size, int32_t *dist) {
  c_queue q;
  q.push(v);
  dist[v] = 0;
  while (q.head != NULL && q.tail != NULL) {
    v = q.tail->data;
    q.pop();
    printf("%d ", v + 1);
    for (int i = 0; i < size; i++) {
      if (G[v][i] >= 1 && dist[i] == -1) {
        q.push(i);
        dist[i] = dist[v] + G[v][i];
      }
    }
  }
}

void bfsd_list(list **l, int32_t v, int32_t size, int32_t *dist) {
  std::queue<int> q;
  list *prv = NULL;
  list *head = NULL;
  q.push(v);
  dist[v] = 0;
  head = l[v];
  while (!q.empty()) {
    v = q.front();
    q.pop();
    printf("%d ", v + 1);
    while (head != NULL) {
      if (dist[head->index - 1] == -1) {
        q.push(head->index - 1);
        dist[head->index - 1] = dist[v] + head->weight;
      }
      /* Отслеживание предыдущего элемента для перехода в другой список смежных
       * вершин. */
      prv = head;
      head = head->next;
    }
    /* Переход в другой список смежных вершин. */
    head = l[prv->index - 1];
  }
}

void c_bfsd_list(list **l, int32_t v, int32_t size, int32_t *dist) {
  c_queue q;
  list *prv = NULL;
  list *head = NULL;
  q.push(v);
  dist[v] = 0;
  head = l[v];
  while (q.head != NULL) {
    v = q.tail->data;
    q.pop();
    std::cout << v + 1 << '\t';
    while (head != NULL) {
      if (dist[head->index - 1] == -1) {
        q.push(head->index - 1);
        dist[head->index - 1] = dist[v] + 1;
      }
      /* Отслеживание предыдущего элемента для перехода в другой список смежных
       * вершин. */
      prv = head;
      head = head->next;
    }
    /* Переход в другой список смежных вершин. */
    head = l[prv->index - 1];
  }
}

void diameter_radius(int32_t **G_weight, int32_t size) {
  int *e = (int *)calloc(size, sizeof(int));
  int *peripheral_v_set = NULL, *center_v_set = NULL;
  int R = 0, D = 0;
  /* Поиск эксцентриситетов графа. */
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (e[i] < G_weight[i][j])
        e[i] = G_weight[i][j];

  R = e[0];
  /* Поиск радиуса и диаметра. */
  for (int i = 0; i < size; i++) {
    if (R > e[i])
      R = e[i];
    if (D < e[i])
      D = e[i];
  }
  int n = 0, k = 0;

  /* Вычисление мощности подмножества центральных и периферийных вершин. */
  for (int i = 0; i < size; i++) {
    printf("e(%d) - %d\n", i + 1, e[i]);
    if (e[i] == D)
      n++;
    if (e[i] == R)
      k++;
  }
  putchar(10);
  printf("Радиус: %d\nДиаметр: %d\n", R, D);

  peripheral_v_set = (int *)calloc(n, sizeof(int));
  center_v_set = (int *)calloc(k, sizeof(int));
  n = 0, k = 0;
  for (int i = 0; i < size; i++) {
    if (e[i] == D) {
      peripheral_v_set[n] = i + 1;
      n++;
    }
    if (e[i] == R) {
      center_v_set[i] = i + 1;
      k++;
    }
  }

  puts("Подмножество всех периферийных вершин:");
  printf("{");
  for (int i = 0; i < n; i++)
    printf(" %d ", peripheral_v_set[i]);
  puts("}");

  puts("Подмножество всех центральных вершин:");
  printf("{");
  for (int i = 0; i < k; i++)
    printf(" %d ", center_v_set[i]);
  puts("}");
  free(peripheral_v_set);
  free(center_v_set);
}
