#include "../graph.h"
#include <cstdio>
#include <ctime>

typedef struct node {
  struct node *next;
  struct node *prev;
  int data;
} node;
node *head = NULL, *tail = NULL;
node *queue_create_node(int data);
void queue_push(int data);
void queue_pop();
void queue_print();
void c_bfs(int32_t **G, int32_t size, int32_t *visited, int32_t v) {
  double start = 0, stop = 0;
  start = clock();
  queue_push(v);
  visited[v] = 1;
  while (head != NULL && tail != NULL) {
    v = tail->data; // q.front();
    queue_pop();
    printf("%d ", v + 1);
    for (int i = 0; i < size; i++) {
      if (G[v][i] == 1 && visited[i] == 0) {
        queue_push(i);
        visited[i] = 1;
      }
    }
  }
  stop = clock();
  printf("\nВремя обхода графа: %lf", (stop - start) / 1000);
}

int main() {
  int32_t size, vertex, **G = NULL, *visited = NULL;
  puts("Введите размер матрицы смежности: ");
  scanf("%d", &size);
  G = generate_adjacency_matrix(size);
  print_adjacency_matrix(G, size);
  visited = (int32_t *)calloc(size, sizeof(int32_t));
  puts("Введите стартовую вершину: ");
  scanf("%d", &vertex);
  puts("Обход в ширину по матрице смежности через собственную очередь: ");
  c_bfs(G, size, visited, vertex - 1);
  return 0;
}

node *queue_create_node(int data) {
  node *p = NULL;
  p = (node *)malloc(sizeof(node));
  if (p == NULL) {
    puts("Error");
    exit(1);
  }
  p->data = data;
  p->next = NULL;
  return p;
}
void queue_push(int data) {
  node *p = NULL;
  p = queue_create_node(data);
  if (head == NULL && p != NULL) {
    head = p;
    tail = p;
  } else if (head != NULL && p != NULL) {
    head->prev = p;
    p->next = head;
    head = p;
  }
  return;
}
void queue_pop() {
  node *p = head;
  node *prv;
  if (head == NULL) // Если список пуст, возвращаемся
    return;
  while (p != tail) // Проход до последнего элемента списка с отслеживанием
                    // предпоследнего
  {
    prv = p;
    p = p->next;
  }

  if (head == tail) // Проверка на то, что в списке 1 элемент
  {
    head = NULL; // Обнуляем голову и хвост
    tail = NULL;
    return;
  }
  free(p);
  prv->next = NULL;
  tail = prv;
  return;
}
void queue_print() {
  node *p = head;
  if (head == NULL)
    puts("Queue is empty");
  printf("->\t");
  while (p) {
    printf("%d\t", p->data);
    p = p->next;
  }
  return;
}