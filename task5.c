#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
/*
   Определение структуры на 3 записи {имя, фамилия, специальность}
*/
struct student
{
   int8_t name[255], surname[255];
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
      puts("1 - Search by name.\n");
      puts("2 - Search by surname.\n");
      puts("3 - Search by the major.\n");
      scanf("%d", &n);
      switch (n)
      {
      case 1:
         char name[255] = "";
         puts("Enter student's name: ");
            
         break;
      
      default:
         break;
      }
   }
   
   
   
   
   
   return 0;
}