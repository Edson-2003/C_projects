#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int size;
	int top;
	int *stack;
};


int
isempty(struct stack *mystack)
{
	return mystack->top == 0 ? 1 : 0;
}

int
isfull(struct stack *mystack)
{
	return mystack->top == mystack->size ? 1 : 0;
}

struct stack*
createstack(int size)
{
	struct stack *mystack = NULL;
	mystack = (struct stack*) malloc(sizeof(struct stack));
	mystack->top = 0;
	mystack->size = size;
	mystack->stack = NULL;
	mystack->stack = (int*) malloc(size * sizeof(int));

	return mystack;
}

void
show(struct stack *mystack)
{
	int i = 0;
	for(i = 0; i < mystack->top; i++)
	{
		printf("%d", mystack->stack[i]);
	}	
}

void 
push(struct stack *mystack, int value)
{
	if(isfull(mystack))
	{
		printf("this stack is full !");
	}
	else
	{
		mystack->stack[mystack->top] = value;
		mystack->top += 1;
	}
}

void
pop(struct stack *mystack)
{
	if(isempty(mystack))
	{
		printf("your stack is empty please add elements before removing it");
	}
	else
	{
		mystack->top -= 1;
	}
}




int
main()
{
	int mysize;
	struct stack *mystack;
	scanf("%d", &mysize);
	mystack = createstack(mysize);
	int i;
	for(i = 0; i < mysize; i++)
	{
		push(mystack, i);
	}
	show(mystack);
	for(i = 0; i < mystack->top; i++)
	{
		pop(mystack);
	}
	free(mystack->stack);
	free(mystack);

	return 0;
}
