
#include <stdlib.h>

struct node
{
  int key;
  struct node *rigth;
  struct node *left;
  struct node *dad;
};

struct tree
{
  struct node *root;
};

struct node*
create_n(int key)
{
  struct node *new;
  new = (struct node*) malloc(sizeof(struct node));
  new->rigth = NULL;
  new->left = NULL;
  new->dad =  NULL;
  new->key = key;

  return new;
}

struct tree*
create_t()
{
  struct tree *new;
  new = (struct tree*) malloc(sizeof(struct tree));
  new->root = NULL;

  return new;
}

void
insert_n(struct node *root, struct node *new)
{  
  new->dad = root;
  if(root->key < new->key)
  {
    if(root->left == NULL)
    {
      root->left = new;
      return;
    }
    return insert_n(root->left, new);
  }
  if(root->key >= new->key)
  {
    if(root->rigth == NULL)
    {
      root->rigth = new;
      return;
    }
    return insert_n(root->rigth, new);
  }
}


void
insert_r(struct tree *tree, int key)
{
  struct node *new;
  new = create_n(key);
  if(tree->root == NULL)
  {
    tree->root = new;
    new->dad = NULL;
    return;
  }
  new->dad = tree->root;
  insert_n(tree->root, new);
}

void
insert_i(struct tree *tree, int key)
{
  struct node *temp;
  temp = tree->root;
  struct node *dad;
  while(temp != NULL)
  {
    dad = temp;
    if(key < temp->key)
    {
      temp = temp->left;
      continue;
    }
    temp = temp->rigth;
  }
  struct node *new;
  new = create_n(key);
  new->dad = dad;
  if(dad == NULL)
  {
    tree->root = new;
    return;
  }
  if(key < dad->key)
  {
    dad->left = new;
    return;
  }
  dad->rigth = new;
}

void
InOrder(struct node *root)
{
  InOrder(root->left);
  printf("%d ", root->key);
  InOrder(root->rigth);
}

void
PreOrder(struct node *root)
{
  printf("%d ", root->key);
  PreOrder(root->left);
  PreOrder(root->rigth);
}

void
PosOrder(struct node *root)
{
  PosOrder(root->left);
  PosOrder(root->rigth);
  printf("%d ", root->key);
}

struct node*
Serch(struct node *root, key)
{
  if(root == NULL)
    return NULL;

  if(root->key = key)
    return root;
  
  if(root->key >= k)
    return serch(root->left, key);
  
  return searc(root->rigth, key);
}


struct node*
Min(struct node *root)
{
  if(root->left != NULL)
    return Min(root->left);
  
  return root;
}

struct node*
Max(struct node *root)
{
  if(root->rigth != NULL)
    return Max(root->rigth);

  return root;
}

struct node*
Successor(struct node *this)
{
  if(this->rigth != NULL)
    return Min(this->rigth);

  struct node *dad;
  dad = this->dad;

  while((dad != NULL) && (dad->rigth == this))
  {
    this = dad;
    dad = dad->dad;
  }
  return dad;
}

void
Transplant(struct tree *tree, struct node *old, struct node *new)
{
  if(old->dad == NULL)
  {
    tree->root = new;
    return;
  }
  
  if(old == old->dad->left)
  {
    old->dad->left = new;
    return
  }

  old->dad->rigth = new;
  if(new != NULL)
    new->dad = old->dad;
}

void
deletion(struct tree *tree, struct node *node)
{
  if(node->rigth == NULL)
  {
    return Transplant(tree, node, node->rigth);
  }
  if(node->left == NULL)
  {
    return Transplant(tree, node, node->left);
  }

  struct node *temp = Min(node->rigth);
  if(temp != node->rigth)
  {
    Transplant(tree, temp, temp->rigth);
    temp->rigth = node->rigth;
    temp->rigth.dad = temp;  
  }
  Transplant(tree, node, temp);
  temp->left = node->left;
  temp->left->dad = temp 

}



int
main()
{

}
