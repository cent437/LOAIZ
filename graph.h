/*
 * Библиотека для  работы с графами.
 */

#include <cstddef>
#include <cstdint>
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
  int32_t weight;
  struct adjacency_list *next;
  struct adjacency_list *prev;

} list;

class c_stack {
public:
  typedef struct stack {
    struct stack *next;
    int data;
  } stack;
  stack *head = NULL, *tail = NULL;
  stack *create_stack_node(int data);
  void push(int data);
  void pop();
};

class c_queue {
public:
  typedef struct node {
    struct node *next;
    struct node *prev;
    int data;
  } node;
  node *head = NULL, *tail = NULL;
  node *create_node(int32_t data);
  void push(int data);
  void pop();
};

/* Генерация матрицы смежности размером matrix_size. */
extern int32_t **generate_adjacency_matrix(int32_t matrix_size);

/* Генерация матрицы смежности для взвешенного графа */
extern int32_t **generate_adjacency_matrix_weight(int32_t matrix_size);
extern int32_t **generate_adjacency_matrix_orient(int32_t matrix_size);
extern int32_t **generate_adjacency_matrix_orient_weight(int32_t matrix_size);

/* Выделение памяти под матрицу инцидентности размером matrix_size. */
extern int32_t **generate_incident_matrix(int32_t rows, int32_t cols);

/* Печать матрицы смежности. Возвращает размер графа. */
extern void print_adjacency_matrix(int32_t **adjacency_matrix,
                                   int32_t matrix_size);

/* Печать матрицы инцидентности. */
extern void print_incident_matrix(int32_t **incident_matrix, int32_t rows,
                                  int32_t cols);

/* Удаление вершины V в графе G. */
extern int32_t **del_vertex(int32_t **G, int32_t size, int32_t V);

/* Отождествление вершин v1 и v2 в графе G. */
extern int32_t **unionV(int32_t **G, int32_t size, int32_t v1, int32_t v2);

/* Стягивание ребра, соединяющего вершины v1 и v2 в графе G. */
extern int32_t **contrV(int32_t **G, int32_t size, int32_t v1, int32_t v2);

/* Расщепление вершины v в графе G. */
extern int32_t **splitV(int32_t **G, int32_t size, int32_t v);

extern int32_t **contrE(int32_t **G, int32_t size, int32_t v1, int32_t v2);

/* Объединение графов G1 и G2. */
extern int32_t **unionG(int32_t **G1, int32_t **G2, int32_t size_G1,
                        int32_t size_G2);

/* Пересечение графов G1 и G2. */
extern int32_t **intersectionG(int32_t **G1, int32_t **G2, int32_t size_G1,
                               int32_t size_G2);
/* Кольцевая сумма графов G1 и G2. */
extern int32_t **xor_G(int32_t **G1, int32_t **G2, int32_t size_G1,
                       int32_t size_G2, int32_t *size_Gtemp);

/* Выделение памяти под новый узел. */
extern list *create_node(int32_t data, int32_t weight);

/* Запись смежной вершины в список смежности. */
extern void push(list **lists_pointer, int32_t data, int32_t weight,
                 int32_t head_index);

/* Создание списка смежности на основе матрицы смежности. */
extern list **create_adjacency_list(int32_t **G, int32_t size);

/* Печать списка смежности. */
extern void print_adjacency_list(list **lists_pointer, int32_t size);

/* Обход в глубину по матрице смежности */
extern void dfs_matrix(int32_t **G, int32_t start, int32_t *visited,
                       int32_t size);

/* Обход в глубину по списку смежности */
extern void dfs_list(list **l, int32_t start, int32_t *visited, int32_t size);

void dfs_no_recursive(int32_t **G, int32_t start, int32_t *visited,
                      int32_t size);

/* Обход в ширину по матрице смежности. */
extern void bfs_matrix(int32_t **G, int32_t size, int32_t *visited, int32_t v);

/* Обход в ширину по списку смежности. */
extern void bfs_list(list **l, int32_t size, int32_t *visited, int32_t v);

/* Обход в ширину с использованием собственной очереди. */
extern void c_bfs(int32_t **G, int32_t size, int32_t *visited, int32_t v);

/* Поиск расстояний методом поиска в ширину по матрице смежности */
extern void bfsd_matrix(int32_t **G, int32_t v, int32_t size, int32_t *dist);

/* Поиск расстояний методом поиска в ширину в списке смежности с использованием
 * контейнера queue */
extern void bfsd_list(list **l, int32_t v, int32_t size, int32_t *dist);

/* Поиск расстояний методом поиска в ширину в списке смежности с использованием
 * собственного класса очереди */
extern void c_bfsd_list(list **l, int32_t v, int32_t size, int32_t *dist);

/* Вывод диаметра и радиуса взвешенного графа. */
extern void diameter_radius(int32_t **G_weight, int32_t size);
