/*
 * Библиотека для  работы с графами.
 */

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

/* Выделение памяти под матрицу инцидентности размером matrix_size. */
extern int32_t **generate_incident_matrix(int32_t rows, int32_t cols);

/* Генерация матрицы смежности размером matrix_size. */
extern int32_t **generate_adjacency_matrix(int32_t matrix_size);

/* Печать матрицы смежности. Возвращает размер графа. */
extern int32_t print_adjacency_matrix(int32_t **adjacency_matrix,
                                      int32_t matrix_size);

/* Печать матрицы инцидентности. */
extern void print_incident_matrix(int32_t **incident_matrix, int32_t rows,
                                  int32_t cols);
extern int32_t **del_vertex(int32_t **G, int32_t size, int32_t V);

/* Выделение памяти под новый узел. */
extern list *create_node(int32_t data);

/* Запись узла в список смежности. */
extern void push(list **lists_pointer, int32_t data, int32_t head_index);

/* Создание списка смежности на основе матрицы смежности. */
extern list **create_adjacency_list(int32_t **G, int32_t size);

/*Печать списка смежности. */
extern void print_adjacency_list(list **lists_pointer, int32_t head_index);

extern int32_t **unionV(int32_t **G, int32_t size, int32_t v1, int32_t v2);

extern int32_t **contrV(int32_t **G, int32_t size, int32_t v1, int32_t v2);

extern int32_t **splitV(int32_t **G, int32_t size, int32_t v);

extern int32_t **contrE(int32_t **G, int32_t size, int32_t v1, int32_t v2);

extern int32_t **unionG(int32_t **G1, int32_t **G2, int32_t size_G1,
                        int32_t size_G2);
extern int32_t **intersectionG(int32_t **G1, int32_t **G2, int32_t size_G1,
                               int32_t size_G2);
extern int32_t **ring_sumG(int32_t **G1, int32_t **G2, int32_t size_G1,
                           int32_t size_G2, int32_t *size_Gtemp);