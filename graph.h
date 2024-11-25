/*
 * Библиотека для  работы с графами.
 */

#include <cstddef>
#include <iso646.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Структура двусвязного списка для
 * представления графа в виде списка
 * смежности.
 */
typedef struct adjacency_list {
  int32_t index;
  struct adjacency_list *next;
  struct adjacency_list *prev;

} list;
class c_queue {
public:
  typedef struct node {
    struct node *next;
    struct node *prev;
    int data;
  } node;
  node *head = NULL, *tail = NULL;
  node *create_node(int data);
  void push(int data);
  void pop();
};

/* Генерация матрицы смежности размером matrix_size. */
extern int32_t **generate_adjacency_matrix(int32_t matrix_size);

/* Печать матрицы смежности. Возвращает размер графа. */
extern void print_adjacency_matrix(int32_t **adjacency_matrix,
                                   int32_t matrix_size);

/* Выделение памяти под новый узел. */
extern list *create_node(int32_t data);

/* Запись смежной вершины в список смежности. */
extern void push(list **lists_pointer, int32_t data, int32_t head_index);

/* Создание списка смежности на основе матрицы смежности. */
extern list **create_adjacency_list(int32_t **G, int32_t size);

/* Печать списка смежности. */
extern void print_adjacency_list(list **lists_pointer, int32_t size);

/* Обход в ширину по матрице смежности. */
extern void bfs_matrix(int32_t **G, int32_t size, int32_t *visited, int32_t v);

/* Обход в ширину по списку смежности. */
extern void bfs_list(list **l, int32_t size, int32_t *visited, int32_t v);

/* Обход в ширину с использованием собственной очереди. */
extern void c_bfs(int32_t **G, int32_t size, int32_t *visited, int32_t v);
