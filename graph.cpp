#include "graph.h"
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
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

void dfsd_matrix(int32_t **G, int32_t v, int32_t size, int32_t *dist,
                 int32_t *visited) {
  visited[v] = 1;
  // dist[v]++;
  printf("%d ", v + 1);
  for (int i = 0; i < size; i++) {

    if (G[v][i] >= 1 and visited[i] == 0 and dist[i] == 0) {
      // dist[v] = 0;
      dist[v] += dist[i];
      dfsd_matrix(G, i, size, dist, visited);
    }
  }
}
