#include "matrix.h"
#include <time.h>

typedef struct adjacency_list {
  int32_t index;
  struct adjacency_list *next;
  struct adjacency_list *prev;

} list;
list *create_node() {
  list *p = NULL;
  char s[20];
  p = (list *)malloc(sizeof(list));
  if (p == NULL) {
    puts("Error");
    exit(1);
  }
  p->next = NULL;
  return p;
}
void push_back(list *list_head, list *list_tail, int32_t data) {
  list *p = NULL;
  p = create_node();
  if (list_head == NULL and
      p != NULL) // Если списка нет, то добавляем элемент в голову и в хвост
  {
    list_head = p;
    list_tail = p;
  } else if (list_head != NULL and
             p != NULL) // Если список есть, то добавляем элемент в конец списка
  {
    list_tail->next = p;
    p->prev = list_tail;
    list_tail = p;
  }
  return;
}
void print(list *head, int32_t head_index) {
  list *p = head;
  if (head == NULL)
    puts("List is empty");
  printf("->\t");
  while (p) {
    printf("%d: %d\t", head_index, p->index);
    putchar('\n');
    p = p->next;
  }
  return;
}
int main() {
  int32_t size = 0, vertex = 0;
  puts("Введите размер матриц:");
  scanf("%d", &size);
  int32_t **G1 = generate_adjacency_matrix(size), **G2 = NULL;
  /* Выделение памяти под список смежности */
  list **l = (list **)calloc(size, sizeof(list *));
  int32_t k = 0;
  for (int32_t i = 0; i < size; i++) {
    l[i] = NULL;
    l[size] = NULL;
    for (int32_t j = 0; j < size; j++) {
      if (G1[i][j] == 1)
        push_back(l[k], l[size], G1[i][j]);
    }
    k ^= k;
  }
  for (int32_t i = 0; i < size; i++) {
    print(l[i], i);
  }

  print_adjacency_matrix(G1, size);
  puts("Введите номер удаляемой вершины:");
  scanf("%d", &vertex);
  G2 = otozhd(G1, size, vertex);
  print_adjacency_matrix(G2, size - 1);

  return 0;
}