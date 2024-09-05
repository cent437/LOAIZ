#include <stdio.h>
#include <string.h>
#include <stdint.h>
/*
   Определение структуры на 3 записи {имя, фамилия, специальность}
*/
struct student
{
   int8_t name[20], surname[20];
   int16_t major;
}stud[3];

int main()
{
   struct student s1;
   for (int32_t i = 0; i < 3; i++)
   {
      puts("Enter student's name: ");
      scanf("%s", stud[i].name);
      rewind(stdin); // Очистка буфера scanf
      puts("Enter student's surname: ");
      scanf("%s", stud[i].surname);
      rewind(stdin);
      puts("Enter student's major: ");
      scanf("%d", &stud[i].major);
      rewind(stdin);
   }
   for (int i = 0; i < 3; i++)
   {
      printf("%s\t%s\t%d\n", stud[i].name, stud[i].surname, stud[i].major);
   }
   for (int n; n != 0; )
   {
      puts("1 - Search by name.");
      puts("2 - Search by surname.");
      puts("3 - Search by the major.");
      puts("0 - Exit.");
      puts("> ");
      scanf("%d", &n);
      switch (n)
      {
      case 0:
         puts("Exit.\n");
         break;
      case 1:
         int8_t name[20] = "";
         puts("Enter student's name: ");
         scanf("%s", name);
         rewind(stdin);
         for (int i = 0; i < 3; i++)
         {
            if (strcmp(name, stud[i].name));
            {
               printf("%s\t%s\t%d\n", stud[i].name, stud[i].surname, stud[i].major);
            }
         }
         break;
      case 2:
         int8_t surname[20] = "";
         puts("Enter student's name: ");
         scanf("%s", name);
         rewind(stdin);
         for (int i = 0; i < 3; i++)
         {
            if (strcmp(surname, stud[i].surname));
            {
               printf("%s\t%s\t%d\n", stud[i].name, stud[i].surname, stud[i].major);
            }
         }
         break;
      case 3:
         int16_t major;
         puts("Enter student's major number: ");
         scanf("%d", &major);
         rewind(stdin);
         for (int i = 0; i < 3; i++)
         {
            if (major == stud[i].major);
            {
               printf("%s\t%s\t%d\n", stud[i].name, stud[i].surname, stud[i].major);
            }
         }
         break;
      }
   }
   
   
   
   
   
   return 0;
}