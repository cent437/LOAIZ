#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


typedef struct list
{
   int data;
   struct list *next;
}l;

l* push_back(int n);
l* push_front(int n);
void print_list(l* p_begin);
void delete_list(l* p_begin);


int main()
{
   
   l* p_begin = push_back(10);
   //print_list(p_begin);
   delete_list(p_begin);
   return 0;
}




l* push_front(int n)
{
   
}
l* push_back(int n)
{
   l* head = NULL;
   l* p = NULL;
   
   // Заполнение списка
   head = (l*)malloc(sizeof(l));
   p = head;
   p->next = NULL;
   p->data = 0;
   
   for (int i = 1; i < n; i++)
   {
      p->next = (l*)malloc(sizeof(l));
      p = p->next;
      p->next = NULL;
      p->data = i;
   }
   return head;
}
void print_list(l* p_begin)
{
   l* p = p_begin;
   while (p != NULL)
   {
      printf("%d \n", p->data);
      p = p->next;
   }
}
void delete_list(l* p_begin)
{
   l* p = p_begin;
   while (p != NULL)
   {
      l* tmp;
      tmp = p;
      p = p->next;
      free(tmp);
   }
   
}