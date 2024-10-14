#include <iso646.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Генерация матрицы смежности размером matrix_size. */
int32_t **generate_adjacency_matrix(int32_t matrix_size);

/* Выделение памяти под матрицу инцидентности размером matrix_size. */
int32_t **generate_incident_matrix(int32_t matrix_size);

/* Печать матрицы инцидентности. */
int32_t print_incident_matrix(int32_t **incident_matrix, int32_t matrix_size);

/* Печать матрицы смежности. */
int32_t print_adjacency_matrix(int32_t **adjacency_matrix, int32_t matrix_size);