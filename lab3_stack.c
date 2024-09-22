#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <string.h>
typedef struct stack
{
  struct stack *next;
  char data[20];
}stack;

stack* head = NULL, *tail = NULL;
stack* create_stack()
{
  stack *p = NULL;
  char s[20];
  p = (stack*)malloc(sizeof(stack));
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
  return p;
}

void pop()
{
  stack *p = head;
  stack *prv;
  if (head == NULL)
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
void push()
{
  stack *p = NULL;
  p = create_stack();
  if (head == NULL and p != NULL) // Если списка нет, то добавляем элемент в голову и в хвост
  {
    head = p;
    tail = p;
  }
  else if (head != NULL and p != NULL) // Если список есть, то добавляем элемент в конец списка
  {
    tail->next = p;
    tail = p;
  }
  return;
}

void print()
{
  stack *p = head;
  if (head == NULL)
    puts("Stack is empty");
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
      push();
      break;
      case 2:
      pop();
      break;
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