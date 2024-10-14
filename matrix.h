#include <iso646.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Выделение памяти под матрицу инцидентности размером matrix_size. */
extern int32_t **generate_incident_matrix(int32_t matrix_size);

/* Генерация матрицы смежности размером matrix_size. */
extern int32_t **generate_adjacency_matrix(int32_t matrix_size);

/* Печать матрицы смежности. */
extern int32_t print_adjacency_matrix(int32_t **adjacency_matrix, int32_t matrix_size);

/* Печать матрицы инцидентности. */
extern int32_t print_incident_matrix(int32_t **incident_matrix, int32_t matrix_size);

