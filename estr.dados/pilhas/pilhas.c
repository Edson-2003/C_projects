#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nome[50];
	int idade;
}Pessoa;


typedef struct nó{
	Pessoa p;
	struct nó *proximo;
}Nó;

Pessoa ler()
{	
	Pessoa p;
	scanf("%d", &p.idade);
	scanf("%s", &p.nome);

	return p;
}


Nó* push(Nó *top)
{
	Nó novo = malloc(sizeof(Nó));

	if(novo)
	{
		novo->p = ler();
		novo->proximo = top;
		
		return novo;		
	}
	else
	{
		printf("deu ruim");
		
		return NULL;
	}
}

Nó* pop(Nó **top)
{
	if(top != NULL)
	{
		Nó *remover = *top;
		*top = remover->proximo
		
		return remover;
	}
	else
	{
		printf("deu ruim");
		return NULL;
	}
}



void imprime no(Nó p)
{ 
	printf("%d %s", p.idade, p.nome);
}
void main()
{
	Nó *top = NULL;
  top = push(top);	
  top = push(top);
  top = push(top);

	remover = pop(&top);
	if(remover)
	{
		printf("elemento removido com sucesso");		
	}
	else
	{
		printf("sem elementos a remover");
	}
	
}
