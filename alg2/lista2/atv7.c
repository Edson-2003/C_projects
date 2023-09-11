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

void somafra(fracao *f1, fracao *f2, fracao *res)
{
    res->denominador = f1->denominador * f2->denominador;
    res->numerador = (f1->numerador * f2->denominador) + (f2->numerador * f1->denominador);
}

void imprimefracao(fracao *x)
{
    printf("%d / %d", x->numerador, x->denominador);
}
void main()
{
    fracao fracao1;
    fracao fracao2;
    fracao res;

    lefracao(&fracao1);
    lefracao(&fracao2);

    somafra(&fracao1, &fracao2, &res);
    
    imprimefracao(&res);
}