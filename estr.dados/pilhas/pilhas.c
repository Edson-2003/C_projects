#include <stdio.h>
#include <stdlib.h>


typedef struct _pilha
{
	int top;
	int tam;
	int *vet;
}pilha;


void inicia(pilha *p)
{

	p = (pilha*) malloc(sizeof(pilha));
	p->top = -1;	

	scanf("%d", &p->tam);
	p->vet = (int*) malloc(p->tam * sizeof(int));
}

int p_cheia(pilha *p)
{
	return((p->top) == (p->tam-1));
}


int p_vazia(pilha *p)
{
	return((p->top)==(-1));
}



void push(pilha *p, int key)
{
	if(p_cheia(p))
	{
		printf("pilha cheia");
	}
	else
	{
		p->top = p->top + 1;
		p->vet[p->top] = key;	
	}
}



void main()
{
	pilha *p;
	inicia(p);
	push(p,1);
}

