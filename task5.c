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
   for (int32_t i = 0; i < 3; i++)
   {
      puts("Enter student's name, surname and major: ");
      scanf("%s %s %d", stud[i].name, stud[i].surname, stud[i].major);
      rewind(stdin); // Очистка буфера scanf
      
   }
   for (int i = 0; i < 3; i++)
   {
      printf("%s\t%s\t%d\n", stud[i].name, stud[i].surname, stud[i].major);
   }
   for (int n; n != 0; )
   {
      puts("1 - Begin search.\n");
      puts("0 - Exit.\n> ");
      scanf("%d", &n);
      switch (n)
      {
      case 1:
         int8_t name[20] = "";
         int8_t surname[20] = "";
         int16_t major;
         puts("Enter student's name, surname and major: ");
         scanf("%s %s %d",name, surname, &major);
         for (int i = 0; i < 3; i++)
         {
            if (strcmp(name, stud[i].name) == 0 and strcmp(surname, stud[i].surname) == 0 and major == stud[i].major)
            {
               printf("%s\t%s\t%d\n", stud[i].name, stud[i].surname, stud[i].major);
            }
            
         }
          
         break;
      }
   }
   puts("Exiting.\n> ");
   
   
   
   
   return 0;
}