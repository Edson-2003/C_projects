#include <stdio.h>

void main (){

    int v1;
    int v2=0;
    int controle=1;
    int aux;

    scanf("%d", &v1);
    for(int i = 0; i<v1; i++)
    {
        aux=v2;
        scanf("%d", &v2);
        if(i!=0)
        {
         if(aux>v2)
         {
         controle=0;
         }
        }
    }
    
printf("%d",controle);

}
