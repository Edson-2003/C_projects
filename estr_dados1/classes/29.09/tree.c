#include <stdio.h>
#include <stdlib.h>



/*
 *	a arvore tem os seguintes elementos, ela é composta por nós(Nó direito e Nó esquerdo) e a
 *	heap(array que representa todos elementos da arvore). Os nós são compostos pelos seguintes elementos
 *
 *
 *
*/
typedef struct node{
	struct node *rigth;
	struct node *left;
	int value;
	int level;
}Node;

typedef struct{
	Node *rigth;
	Node *left;
	int *heap;
}Tree;

void main()
{
	
}
