#include <stdio.h>
#include <iso646.h>
#include <stdint.h>
#include <string.h>

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
   int n;
   for (int32_t i = 0; i < 3; i++)
   {
      puts("Enter student's data (name, surname, major): ");
      scanf("%s %s %d", stud[i].name, stud[i].surname, &stud[i].major);
      rewind(stdin); // Очистка буфера scanf
   }
   for (int i = 0; i < 3; i++)
   {
      printf("%s\t%s\t%d\n", stud[i].name, stud[i].surname, stud[i].major);
   }
   puts("1 - Begin search.");
   puts("0 - Exit.\n> ");
   scanf("%d", &n);
   for (; n != 0; )
   {
      int8_t name[20] = "";
      int8_t surname[20] = "";
      int16_t major;
      puts("Enter student's major: ");
      scanf("%d", &major);
      
      puts("Enter student's name: ");
      scanf("%20s", name);
      rewind(stdin);
      
      puts("Enter student's surname: ");
      scanf("%20s", surname);
      rewind(stdin);

      for (int i = 0; i < 3; i++)
      {
         if (strcmp(name, stud[i].name) == 0 and strcmp(surname, stud[i].surname) == 0 and major == stud[i].major)
            printf("%s\t%s\t%d\n", stud[i].name, stud[i].surname, stud[i].major);
      }
      puts("1 - Begin search.");
      puts("0 - Exit.\n> ");
      scanf("%d", &n);
   }
   puts("Exiting.\n");
   return 0;
}