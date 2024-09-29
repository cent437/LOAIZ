#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>
typedef struct node
{
   int32_t data;
   struct node *left;
   struct node *right;

} node;
node *root;
node *CreateTree(node *root, node *r, int32_t data)
{
   if (r == NULL)
   {
      r = (node *)malloc(sizeof(node)); // Выделение памяти под новую ветвь дерева
      if (r == NULL)
      {
         puts("Error");
         exit(0);
      }
      r->left = NULL;
      r->right = NULL;
      r->data = data;
      if (root == NULL)
         return r;
      if (data > root->data) // Если введенное число больше числа в корне, переходим в левую ветку
         root->left = r;
      else
         root->right = r; // Иначе в правую ветку
      return r;
   }
   if (data > r->data) // Добавление в существующее дерево нового элемента по той же логике
      CreateTree(r, r->left, data);
   else
      CreateTree(r, r->right, data);
   return root;
}
void print_tree(node *r, int l)
{
   if (r == NULL)
      return;

   print_tree(r->right, l + 1);
   for (int i = 0; i < l; i++)
   {
      printf("-\t");
   }
   printf("%d\n", r->data);
   print_tree(r->left, l + 1);
}
void build_tree()
{
   int32_t D, start = 1;
   puts("-1 - end of tree build");
   while (start)
   {
      puts("Enter the number:");
      scanf("%d", &D);
      if (D == -1)
      {
         puts("Tree building has finished.");
         start = 0;
      }
      else
         root = CreateTree(root, root, D);
   }
}
void search(node *r, int32_t n)
{
   if (r == NULL) // Если в ходе переходов элемент не нашелся, выводим сообщение о его отсутствии.
   {
      puts("Element not found.");
      return;
   }
   if (n == r->data) // Если элемент нашелся в дереве, выводим сообщение об этом.
   {
      puts("Element found.");
      return;
   }
   else if (n > r->data) // Иначе проходим по дереву дальше
   {
      r = r->left;
      search(r, n);
   }
   else if (n < r->data)
   {
      r = r->right;
      search(r, n);
   }
}
void count_of(node *r, int32_t n, int32_t i)
{
   if (r == NULL)
   {
      printf("There are %d elements %d in this tree.\n", i, n);
      return;
   }
   if (n == r->data) // Если элемент совпал с элементом в дереве, прибавляем к счетчику 1.
   {
      i++;
      if (n > r->data)
      {
         r = r->left;
         count_of(r, n, i);
      }
      else
      {
         r = r->right;
         count_of(r, n, i);
      }
   }
   else if (n > r->data)
   {
      r = r->left;
      count_of(r, n, i);
   }
   else if (n < r->data)
   {
      r = r->right;
      count_of(r, n, i);
   }
}
int main()
{
   int n = -1;
   int x;
   while (n != 0)
   {

      puts("1. Create tree");
      puts("2. Search the element");
      puts("3. Count of N elements");
      puts("0. Stop");
      scanf("%d", &n);
      switch (n)
      {
      case 1:
         build_tree();
         print_tree(root, 0);
         break;
      case 2:
         puts("Enter the number to search:");
         scanf("%d", &x);
         search(root, x);
         break;
      case 3:
         puts("Enter the number to count:");
         scanf("%d", &x);
         count_of(root, x, 0);
         break;
      }
   }
   return 0;
}