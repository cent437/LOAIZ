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

int main()
{
   print_tree(root, 0);
   getchar();
   return 0;
}