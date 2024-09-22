#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct node
{
   char inf[256]; // полезная информация
   struct node *next; // ссылка на следующий элемент
}node;
node *head = NULL, *last = NULL, *f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;

node* get_struct(void)
{
   node *p = NULL;
   char s[256];
   if ((p = (node*)malloc(sizeof(node))) == NULL) // выделяем память под новый элемент списка
   {
      printf("Error allocating memory\n");
      exit(1);
   }
      printf("Enter object name: \n"); // вводим данные
      scanf("%s", s);
   if (*s == 0)
   {
      printf("The recording wasn't made\n");
      return NULL;
   }
   strcpy(p->inf, s);
   p->next = NULL;
   return p; // возвращаем указатель на созданный элемент
}
/* Последовательное добавление в список элемента (в конец)*/

void push(void)
{
   node *p = NULL;
   p = get_struct();
   if (head == NULL && p != NULL) // если списка нет, то устанавливаем голову списка
   {
      head = p;
      last = p;
   }
   else if (head != NULL && p != NULL) // список уже есть, то вставляем в конец
   {
      last->next = p;
      last = p;
   }
   return;
}
void print(void)
{
   node *struc = head;
   if (head == NULL)
   {
      puts("Stack is empty.");
   }
   printf("->\t");
   while (struc)
   {
      printf("%s \t", struc->inf);
      struc = struc->next;
   }
   return;
}

/*Удаление элемента в конце очереди*/
void pop(void)
{
   node *struc = last; // указатель, проходящий по очереди установлен на начало списка
   node* prev;
   prev = struc;
   struc = struc->next;
   if (struc == NULL) // если голова списка равна NULL, то список пуст
      return;
   prev->next = NULL;
   free(struc); // удаляем последний элемент
   //struc = last; 
}


int main()
{
   setlocale(LC_ALL, "ru_RU.UTF-8");
   int n;
   puts("Enter stack size:");
   scanf("%d", &n);
   rewind(stdin);
   for (int i = 0; i < n; i++)
   {
      push();
   }
   puts("Stack is full.");
   print();
   puts("\n1. Delete");
   puts("0. Finish");
   
   while(n != 0)
   {
      scanf("%d", &n);
      rewind(stdin);
      if (n == 1)
         pop();

      print();   
      puts("\n1. Delete");
      puts("0. Finish");
   }

   return 0;
}