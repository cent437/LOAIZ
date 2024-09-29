#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>
#include <time.h>
#include <limits.h>
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
      // if (data == root->data)
      // {
      //    puts("You can't add similar elements in this tree");
      //    return r;
      // }
      if (data > root->data) // Если введенное число больше числа в корне, переходим в левую ветку
         root->left = r;
      else
         root->right = r; // Иначе в правую ветку
      return r;
   }
   // if (data == r->data)
   // {
   //    puts("You can't add similar elements in this tree"); // Если введенное число совпадает с корнем, то не добавляем его.
   //    return r;
   // }
   else if (data > r->data) // Добавление в существующее дерево нового элемента по той же логике
      CreateTree(r, r->left, data);
   else
      CreateTree(r, r->right, data);
   return root;
}
void print_tree(node *r, int l, FILE *t)
{
   if (r == NULL)
      return;

   print_tree(r->right, l + 1, t);
   for (int i = 0; i < l; i++)
   {
      //printf("-\t");
      fprintf(t, "-\t");
   }
   //printf("%d\n", r->data);
   fprintf(t, "%d\n", r->data);
   print_tree(r->left, l + 1, t);
}
void generate_tree(size_t tree_size)
{
   srand(time(NULL));
   puts("Filling tree...");
   for (size_t i = 0; i < tree_size; i++)
   {
      root = CreateTree(root, root, rand());
   }
   puts("Tree is full.");
}
double add_to_the_tree_time() // Функция измерения времени добавления нового элемента в существующее дерево
{
   srand(time(NULL));
   double start, stop;
   start = clock();
   root = CreateTree(root, root, rand());
   stop = clock();
   return (stop - start) / CLOCKS_PER_SEC;
}
void search(node *r, int32_t n)
{
   if (r == NULL)
   {
      puts("Element not found.");
      return;
   }
   if (n == r->data)
   {
      puts("Element found.");
      return;
   }
   else if (n > r->data)
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

int main()
{
   FILE *t = fopen("tree.txt", "w");
   int32_t n = -1;
   size_t x;
   while (n != 0)
   {

      puts("1. Create tree");
      puts("2. Measure time of adding.");
      puts("0. Stop");
      scanf("%d", &n);
      switch (n)
      {
      case 1:
         puts("Enter the tree size: ");
         scanf("%d", &x);
         if (x > UINT64_MAX)
         {
            puts("Memory overflow");
            exit(-1);
         }
         generate_tree(x);
         print_tree(root, 0, t);
         break;
      case 2:
         printf("%lf", add_to_the_tree_time());
         break;
      }
   }
   fclose(t);
   return 0;
}