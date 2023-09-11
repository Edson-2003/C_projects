#include <stdio.h>

typedef struct
{
    int numerador;
    int denominador;
}fracao;

void lefracao(fracao *x)
{
    scanf("%d", &x->numerador);
    scanf("%d", &x->denominador);
}

void imprimefracao(fracao *x)
{
    printf("%d / %d", x->numerador, x->denominador);
}

void simplifica(fracao *x)
{
    int maxdiv = 1;
    if(x->denominador > x->numerador)
    {
        for(int i = 1; i < x->denominador; i++)
        {
        if((x->denominador % i == 0) && (x->numerador % i == 0))
        {
            maxdiv = i;
        }
        }    
    }

    else
    {
        for(int i = 1; i < x->numerador; i++)
        {
            if((x->denominador % i == 0) && (x->numerador % i == 0))
            {
                maxdiv = i;
            }
        }
    }

    x->denominador = x->denominador / maxdiv;
    x->numerador = x->numerador / maxdiv; 
}

void main()
{
    fracao fracao;

    lefracao(&fracao);
    simplifica(&fracao);

    imprimefracao(&fracao);
}