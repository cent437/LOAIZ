#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <string.h>
typedef struct node
{
  struct node *next;
  struct node *prev;
  char data[20];
  int len;
}node;

node* head = NULL, *tail = NULL;
node* create_node()
{
  node *p = NULL;
  char s[20];
  p = (node*)malloc(sizeof(node));
  if (p == NULL)
  {
    puts("Error");
    exit(1);
  }
  puts("Enter object name:"); // вводим данные
  scanf("%s", s);
  rewind(stdin);
  if (*s == 0)
  {
     puts("The recording wasn't made"); // вводим данные
     return NULL;
  }
  strcpy(p->data, s);
  p->len = strlen(s);
  p->next = NULL;
  return p;
}
void push_here(node* position, node* p)
{
  if (position == NULL) // Если позиция указывает на несуществующий элемент, добавляем в конец списка
  {
    tail->next = p;
    p->prev = tail;
    tail = p;
    return;
  }
  else if (head != NULL and p != NULL)
  {
    p->prev = NULL;
    p->next = NULL;
    
    p->next = position;
    p->prev = position->prev;
    if (position->prev)
    {
      position->prev->next = p;
  
    }
    position->prev = p;
  }  
  
  return;
}
void push()
{
  node *p = NULL;
  node *position = NULL;
  node *nxt = NULL;
  p = create_node(); // Помещаем новый элемент в указатель p 
  if (head == NULL and p != NULL) // Если списка нет, то добавляем элемент в голову и в хвост
  {
    head = p;
    tail = p;
  }
  else if (head != NULL and p != NULL) // Если список есть, то добавляем элемент в начало списка
  {
    nxt = head; // Присваиваем начало списка
    if (p->len <= head->len) // Если введеный элемен
    {
      head->prev = p;
      p->next = head;
      head = p;
    }
    if (p->len > head->len) // Если введенная строка больше первой
    {
      position = head;
      while (p->len != position->len)
      {
        position = nxt; // Меняем позицию, относительно которой будем добавлять узел 
        if (nxt == NULL) break; // Если список закончился, прекращаем проход по нему
        nxt = nxt->next;
      }
      //if (nxt == NULL)
      //  position = nxt;
      push_here(position, p);

    }
    
  }
  return;
}
void pop()
{
  node *p = head;
  node *prv;
  if (head == NULL) // Если список пуст, возвращаемся
    return;
  while (p != tail) // Проход до последнего элемента списка с отслеживанием предпоследнего
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
void print()
{
  node *p = head;
  if (head == NULL)
    puts("Queue is empty");
  printf("->\t");
  while(p)
  {
    printf("%s\t", p->data);
    p = p->next;
  }
  return;
}
int main()
{
  int n = -1;
   while(n != 0)
    {
     switch (n)
     {
      case 1:
      push();break;
      case 2:
      pop(); break;
     }

     print();
     puts("\n1. Add");
     puts("2. Delete");
     puts("0. Stop");
     scanf("%d", &n);
     rewind(stdin);
    }
  
  return 0;
}