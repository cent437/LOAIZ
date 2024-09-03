#include <stdio.h>
#include <malloc.h>
struct student
{
   char name[255];
   char surname[255];
   short major;
   int* next;
};

int main()
{
   int n = 0;
   puts("Enter the size of the database: ");
   scanf("%d", &n);
   struct student* s1 = (struct student*)malloc(sizeof(struct student));
   puts("Name: ");
   scanf("%s", s1->name);
   
   puts("Surname: ");
   scanf("%s", s1->surname);
   
   puts("Number of the major: ");
   scanf("%d", &s1->major);
   for (int i = 0; i < n; i++)
   {
      s1->next = (struct student*)malloc(sizeof(struct student));
      puts("Name: ");
      scanf("%s", s1->name);
   
      puts("Surname: ");
      scanf("%s", s1->surname);
   
      puts("Number of the major: ");
      scanf("%d", &s1->major);
   }
   s1->next = NULL;
   for (;s1->next != NULL ;)
   {
      printf("\t|%s|\t|%s|\t|%d|\n", s1->name, s1->surname, s1->major);
   }
   return 0;
}