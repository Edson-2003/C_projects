#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
  bool isblack;
  int key;
  struct node *dad;
  struct node *rigth;
  struct node *left;
};

struct NIL
{
  struct node *root;
};

struct tree
{
  struct node *NIL;
  struct node *root;
};

struct tree*
create_t()
{
  struct tree *new;
  new = (struct tree *) malloc(sizeof(struct tree));
  new->NIL->root = new->root;
  new->root = NULL;
}

struct node*
create_n(struct tree *tree, int key)
{
  struct node *new;
  new = (struct node *) malloc(sizeof(struct node));
  new->rigth = tree->NIL;
  new->left = tree->NIL;
  new->key = key;
}

void 
insert_n(struct node *root, struct node *new)
{
  if(tree->root = NULL)
  {
    tree->root = new;
    return;
  }
  
  new->dad = root;
  if(new->key > root->key)
  {
    if(root->rigth != NULL)
    {
      insert_n(root->rigth, new);
      return;
    }
    
    root->rigth = new;
  }

  if(root->left != NULL)
  {
    insert_n(root->left, new);
    return;
  }
  root->left = new;
}

void
insert(struct tree *tree, int key)
{
  struct node *new;
  new = create_n(tree, key);
  if(tree->root != NULL)
  {
    new->dad = tree->root;
  }
  insert_n(tree->root, new);
  new->isblack = !new->dad->isblack;
  tree->root = true;
}


int
main()
{

}
