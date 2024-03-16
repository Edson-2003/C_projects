#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *p;
  struct node *left;
  struct node *right;
  int key;
};

struct tree
{
  struct node *root;
};

struct node*
create_node(int key)
{
  struct node *new;
  new = (struct node *) malloc(sizeof(struct node));
  new->p = NULL;
  new->left = NULL;
  new->right = NULL;
  new->key = key;

  return new;
}

struct tree*
create_tree()
{
  struct tree *new;
  new = (struct tree *) malloc(sizeof(struct tree));
  new->root = NULL;

  return new;
}

void
insert_tree(struct node *root, int key)
{
  if(root == NULL)
  {
    struct node *new;
    new = create_node(key);
    root = new;
    return;
  }
  
  if(root->key < key)
  {
    insert_tree(root->left, key);
    return;
  }
  
  struct node *new;
  new = create_node(key);
  new->p = root;
  root->right = new;
}


void
inorder_walk(struct node *root)
{
  if(root != NULL)
  {
    inorder_walk(root->left);
    printf("%d ", root->key);
    inorder_walk(root->right);
  }
}

int
main()
{
  struct tree *new = create_tree();
  for(int i = 5; i < 10; i++)
  {
    insert_tree(new->root, i);
  }
  for(int i = 0; i < 5; i++)
  {
    insert_tree(new->root, i);
  }
  inorder_walk(new->root);
  return 0;
}
