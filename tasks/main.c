#include "../graph.h"
#include <stdint.h>
#include <stdio.h>
int main() {
  int32_t **G1 = NULL, **G2 = NULL, **G3 = NULL, size_G1 = 0, size_G2 = 0,
          size_G3 = 0, v1 = 0, v2 = 0, ui_switch = -1, graph_num = 0,
          sizemax = 0, sizemin = 0;
  list **adjacency_list = NULL;
  puts("Создание графов G1 и G2.");
  puts("Введите размер матриц:");
  scanf("%d %d", &size_G1, &size_G2);
  sizemax = (size_G1 > size_G2) ? size_G1 : size_G2;
  sizemin = (size_G1 < size_G2) ? size_G1 : size_G2;
  G1 = generate_adjacency_matrix(size_G1);
  print_adjacency_matrix(G1, size_G1);
  putchar('\n');
  G2 = generate_adjacency_matrix(size_G2);
  print_adjacency_matrix(G2, size_G2);
  while (ui_switch != 0) {
    switch (ui_switch) {
    case 1: /* Отождествление вершин */
      puts("Выберите граф для операции.");
      puts("1 - G1.");
      puts("2 - G2.");
      scanf("%d", &graph_num);
      switch (graph_num) {
      case 1:
        puts("Введите индексы вершин через пробел");
        scanf("%d %d", &v1, &v2);
        G1 = unionV(G1, size_G1, v1, v2);
        print_adjacency_matrix(G1, size_G1 - 1);
        break;
      case 2:
        puts("Введите индексы вершин через пробел");
        scanf("%d %d", &v1, &v2);
        G1 = unionV(G1, size_G2, v1, v2);
        print_adjacency_matrix(G1, size_G2 - 1);
        break;
      }
      break;
    case 2: /* Стягивание ребра */
      puts("Выберите граф для операции.");
      puts("1 - G1.");
      puts("2 - G2.");
      scanf("%d", &graph_num);
      switch (graph_num) {
      case 1:
        if (G1 == NULL) {
          puts("Графа G1 не существует");
          break;
        }
        puts("Введите индексы вершин через пробел");
        scanf("%d %d", &v1, &v2);
        G3 = contrV(G1, size_G1, v1, v2);
        print_adjacency_matrix(G3, size_G1 - 1);
        break;
      case 2:
        if (G2 == NULL) {
          puts("Графа G2 не существует");
          break;
        }
        puts("Введите индексы вершин через пробел");
        scanf("%d %d", &v1, &v2);
        G3 = contrV(G2, size_G2, v1, v2);
        print_adjacency_matrix(G3, size_G2 - 1);
        break;
      }
      break;
    case 3: /* Расщепление вершин */
      puts("Выберите граф для операции.");
      puts("1 - G1.");
      puts("2 - G2.");
      scanf("%d", &graph_num);
      switch (graph_num) {
      case 1:
        puts("Введите индексы вершин через пробел");
        scanf("%d", &v1);
        G3 = splitV(G1, size_G1, v1);
        print_adjacency_matrix(G3, size_G1 + 1);
        break;
      case 2:
        puts("Введите индексы вершин через пробел");
        scanf("%d", &v1);
        G3 = splitV(G2, size_G2, v1);
        print_adjacency_matrix(G3, size_G2 + 1);
        break;
      }
      break;
    case 4: /* Объединение графов */
      puts("G1 ∪ G2:");
      G3 = unionG(G1, G2, size_G1, size_G2);
      print_adjacency_matrix(G3, sizemax);
      break;
    case 5: /* Пересечение графов */
      puts("G1 ∩ G2:");
      G3 = intersectionG(G1, G2, size_G1, size_G2);
      print_adjacency_matrix(G3, sizemin);
      break;
    case 6: /* Кольцевая сумма */
      puts("G1⊕ G2:");
      G3 = ring_sumG(G1, G2, size_G1, size_G2, &size_G3);
      print_adjacency_matrix(G3, size_G3);
      break;
    case 7: /* Список смeжности */
      puts("Выберите граф для операции.");
      puts("1 - G1.");
      puts("2 - G2.");
      int32_t t;
      scanf("%d", &graph_num);
      switch (graph_num) {
      case 1:
        adjacency_list = create_adjacency_list(G1, size_G1);
        break;
      case 2:
        adjacency_list = create_adjacency_list(G2, size_G2);
        break;
      }
      break;
    }

    putchar('\n');
    putchar('\n');
    puts("1. Выполнить отождествление вершин.");
    puts("2. Выполнить стягивание ребра.");
    puts("3. Выполнить расщепление вершин.");
    puts("4. Выполнить объединение двух графов.");
    puts("5. Выполнить пересечение двух графов.");
    puts("6. Выполнить кольцевую суммц двух графов.");
    puts("7. Создать список смежности.");
    puts("0. Выход.");
    printf("-> ");
    scanf("%d", &ui_switch);
  }

  if (!G1) {
    for (int32_t i = 0; i < size_G1; i++)
      free(G1[i]);
    free(G1);
  }
  if (!G2) {
    for (int32_t i = 0; i < size_G2; i++)
      free(G2[i]);
    free(G2);
  }

  return 0;
}