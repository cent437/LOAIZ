#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <string.h>
typedef struct node
{
  struct node *next;
  struct node *prev;
  char data[20];
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
  p->next = NULL;
  p->prev = NULL;
  return p;
}
void push_front()
{
  node *p = NULL;
  p = create_node();
  if (head == NULL and p != NULL) // Если списка нет, то добавляем элемент в голову и в хвост
  {
    head = p;
    tail = p;
  }
  else if (head != NULL and p != NULL) // Если список есть, то добавляем элемент в начало списка
  {
    head->prev = p;
    p->next = head;
    head = p;
  }
  return;
}
void pop_back()
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
void pop_front()
{
  node *p = head;
  if (head == NULL)
    return;
  head = p->next;
  free(p);
  p = head;
  return;
}
void push_back()
{
  node *p = NULL;
  node *prv = NULL;
  p = create_node();
  if (head == NULL and p != NULL) // Если списка нет, то добавляем элемент в голову и в хвост
  {
    head = p;
    tail = p;
  }
  else if (head != NULL and p != NULL) // Если список есть, то добавляем элемент в конец списка
  {
    tail->next = p;
    p->prev = tail;
    tail = p;
  }
  return;
}
void push(node* pos)
{
  node *p = NULL;
  node* prv = NULL;
  p = create_node();
  if (pos == NULL)
  {
    tail->next = p;
    tail = p;
    return;
  }
  else if (head != NULL and p != NULL)
  {

    p->next = pos;
    p->prev = pos->prev;
    if (pos->prev)
    {
      pos->prev->next = p;
    }
    pos->prev = p;
  }  
  return;
}
void print()
{
  node *p = head;
  if (head == NULL)
    puts("List is empty");
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
      push_front();break;
      case 2:
      push_back(); break;
      case 3:
      node* c = head->next;
      push(c->next); break;
      case 4:
      pop_front(); break;
      case 5:
      pop_back(); break;

     }

     print();
     puts("\n1. Add to begin");
     puts("2. Add to end");
     puts("3. Add elsewhere");
     puts("4. Delete first element");
     puts("5. Delete last element");
     puts("0. Stop");
     scanf("%d", &n);
     rewind(stdin);
    }
  
  return 0;
}