#include "graph.h"
#include <cstddef>
#include <ctime>
#include <iostream>
#include <queue>

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

int32_t **del_vertex(int32_t **G, int32_t size, int32_t V) {
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
  for (int32_t i = 0; i < size; i++) {
    if (i == V)
      free(G[i]);
  }
  return G_new;
}

int32_t **contrV(int32_t **G, int32_t size, int32_t v1, int32_t v2) {
  G[v1 - 1][v2 - 1] = 0;
  G[v2 - 1][v1 - 1] = 0;
  G = unionV(G, size, v1, v2);
  return G;
}

int32_t **unionV(int32_t **G, int32_t size, int32_t v1, int32_t v2) {
  for (int32_t i = 0; i < size; i++) {
    if (G[v2 - 1][i] == 1) {
      G[v1 - 1][i] = G[v2][i];
      // G[i][v1] = G[i][v2];
    }
  }
  del_vertex(G, size, v2);
  return G;
}
int32_t **splitV(int32_t **G, int32_t size, int32_t v) {
  int32_t **Gtemp = generate_adjacency_matrix(size + 1);
  for (int32_t i = 0; i < size; i++) {
    Gtemp[i][size] = G[i][v];
    Gtemp[size][i] = G[v][i];
  }
  for (int32_t i = 0; i < size; i++) {
    for (int32_t j = 0; j < size; i++) {
      Gtemp[i][j] = G[i][j];
    }
  }
  Gtemp[v][v] = 0;
  Gtemp[size + 1][size + 1] = 0;
  for (int32_t i = 0; i < size; i++) {
    free(G[i]);
  }
  free(G);
  G = NULL;
  return Gtemp;
}

int32_t **unionG(int32_t **G1, int32_t **G2, int32_t size_G1, int32_t size_G2) {
  int32_t **Gtemp = NULL;
  if (size_G1 >= size_G2) {
    Gtemp = generate_adjacency_matrix(size_G1);
    for (int32_t i = 0; i < size_G2; i++) {
      for (int32_t j = 0; j < size_G2; j++) {
        Gtemp[i][j] = G1[i][j] bitor G2[i][j];
      }
    }
  } else if (size_G2 >= size_G1) {
    Gtemp = generate_adjacency_matrix(size_G2);
    for (int32_t i = 0; i < size_G1; i++) {
      for (int32_t j = 0; j < size_G1; j++) {
        Gtemp[i][j] = G1[i][j] bitor G2[i][j];
      }
    }
  }
  return Gtemp;
}

int32_t **intersectionG(int32_t **G1, int32_t **G2, int32_t size_G1,
                        int32_t size_G2) {
  int32_t **Gtemp = NULL;
  if (size_G1 <= size_G2) {
    Gtemp = generate_adjacency_matrix(size_G1);
    for (int32_t i = 0; i < size_G1; i++) {
      for (int32_t j = 0; j < size_G1; j++) {
        Gtemp[i][j] = G1[i][j] bitand G2[i][j];
      }
    }
  } else if (size_G2 <= size_G1) {
    Gtemp = generate_adjacency_matrix(size_G2);
    for (int32_t i = 0; i < size_G2; i++) {
      for (int32_t j = 0; j < size_G2; j++) {
        Gtemp[i][j] = G1[i][j] bitand G2[i][j];
      }
    }
  }

  return Gtemp;
}

int32_t **xor_G(int32_t **G1, int32_t **G2, int32_t size_G1, int32_t size_G2,
                int32_t *size_Gtemp) {
  int32_t sizemin, sizemax;
  int32_t **Gtemp = NULL;
  if (size_G1 >= size_G2) {
    sizemin = size_G2;
    sizemax = size_G1;
    Gtemp = generate_adjacency_matrix(sizemax);
    for (int32_t i = 0; i < sizemin; i++) // xor из минимального графа
      for (int32_t j = 0; j < sizemin; j++)
        Gtemp[i][j] = G1[i][j] xor G2[i][j];

    for (int32_t i = 0; i < sizemin; i++)
      for (int32_t j = sizemin; j < sizemax; j++) //
        Gtemp[i][j] = G1[i][j];

    for (int32_t i = sizemin; i < sizemax; i++)
      for (int32_t j = 0; j < sizemax; j++)
        Gtemp[i][j] = G1[i][j];
    int32_t step = 0;
    for (int32_t i = 0; i < sizemax; i++) {

      for (int32_t j = 0; j < sizemax; j++) {
        step += Gtemp[i][j];
      }
      if (step == 0) {
        Gtemp = del_vertex(Gtemp, sizemax, i);
        i--;
        sizemax--;
      }
      step = 0;
    }

  } else if (size_G2 >= size_G1) {
    sizemin = size_G1;
    sizemax = size_G2;
    Gtemp = generate_adjacency_matrix(sizemax);
    for (int32_t i = 0; i < sizemin; i++) // xor из минимального графа
      for (int32_t j = 0; j < sizemin; j++)
        Gtemp[i][j] = G1[i][j] ^ G2[i][j];

    for (int32_t i = 0; i < sizemin; i++)
      for (int32_t j = sizemin; j < sizemax; j++) //
        Gtemp[i][j] = G2[i][j];

    for (int32_t i = sizemin; i < sizemax; i++)
      for (int32_t j = 0; j < sizemax; j++)
        Gtemp[i][j] = G2[i][j];

    int32_t step = 0;
    for (int32_t i = 0; i < sizemax; i++) {
      step = 0;
      for (int32_t j = 0; j < sizemax; j++) {
        if (Gtemp[i][j] == 1)
          step++;
      }
      if (step == 0) {
        Gtemp = del_vertex(Gtemp, sizemax, i);
        i--;
        sizemax--;
      }
    }
  }
  *size_Gtemp = sizemax;
  return Gtemp;
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
void bfs_matrix(int32_t **G, int32_t size, int32_t *visited, int32_t v) {
  double start = clock(), stop = 0;
  std::queue<int32_t> q;
  q.push(v);
  visited[v] = 1;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    std::cout << v + 1 << ' ';
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
  std::queue<int32_t> q;
  list *prv = NULL;
  q.push(v);
  visited[v] = 1;
  /* Переход в стартовый список смежных вершин. */
  list *head = l[v];
  while (!q.empty()) {
    v = q.front();
    q.pop();
    std::cout << v + 1 << ' ';
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
