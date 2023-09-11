#include <stdio.h>
#include <stdlib.h>

int* intersecao(int *v1, int *v2, int n1, int n2, int *qat)
{
    int cont = 0;
    int repetiu = 0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(v1[i] == v2[j])
            {
            v1[cont] = v2[j];
            cont++;
            break;
            }
        }
    } 
    
    int *v3 = malloc(cont * sizeof(int));
    *qat = cont;
    
    for(int i = 0;i<cont;i++)
    {
    v3[i] = v1[i];
    }

return v3;
}


int main()
{
    int n1, n2, *v3, qat;
    scanf("%d %d", &n1, &n2);
    int v1[n1], v2[n2];

    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &v1[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &v2[i]);
    }
        

    v3 = intersecao(v1, v2, n1, n2, &qat);

    for (int i = 0; i < qat; i++)
    {
        printf("%d ", v3[i]);
    }
    printf("\n");

    return 0;
}