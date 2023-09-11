#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
}data;

void entrada(data *d)
{
    scanf("%d", &d->dia);
    scanf("%d", &d->mes);
    scanf("%d", &d->ano);
}
void main()
{
    int n = 2;
    data d1, d2;
    entrada(&d1);
    entrada(&d2);
    
    if(d1.ano == d2.ano)
    {
        if(d1.mes == d2.mes)
        {
            if(d1.dia != d2.dia)
            {
                if(d1.dia > d2.dia)
                {
                    printf("%d/%d/%d", d2.dia, d2.mes, d2.ano);
                }
                else
                {
                    printf("%d/%d/%d", d1.dia, d1.mes, d1.ano);
                }
            }
        }
        else
        {
            if(d1.mes > d2.mes)
            {
                printf("%d/%d/%d", d2.dia, d2.mes, d2.ano);
            }
            else
            {
                printf("%d/%d/%d", d1.dia, d1.mes, d1.ano);
            }
        }
    }
    else
    {
        if(d1.ano > d2.ano)
        {
            printf("%d/%d/%d", d2.dia, d2.mes, d2.ano);
        }
        else
        {
            printf("%d/%d/%d", d1.dia, d1.mes, d1.ano);
        }
    }
}