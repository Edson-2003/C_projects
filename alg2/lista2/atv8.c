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

void saida(data d[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d/%d/%d", d[1].dia, d[i].mes, d[i].ano);
    }
}

int compara_data(data d1, data d2)
{
    if(d1.ano < d2.ano)
    {
        return -1;
    }
    if(d1.ano > d2.ano)
    {
        return 1;
    }
    if(d1.ano == d2.ano)
    {
        if(d1.mes < d2.mes)
        {
            return -1;
        }
        if(d1.mes > d2.mes)
        {
            return 1;
        }

        if(d1.mes == d2.mes)
        {
            if(d1.dia > d2.dia)
            {
                return 1;
            }
            if(d1.dia < d2.dia)
            {
                return -1;
            }
            if(d1.dia == d2.dia)
            {
                return 0;
            }
        }
    }
}

void trocadatas(data *d1, data *d2)
{
    data temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}

void bubble_sort_data(data datas[], int n)
{

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if(compara_data(datas [j], datas [j+1]) > 0)
            {
                trocadatas(&datas [j], &datas [j+1]);
            }
        }
    }

}

void main()
{
    int n;
    scanf("%d", &n);

    data datas[n];
    entrada(&datas);
    bubble_sort_data(datas, n);
    saida(datas, n);
    
}