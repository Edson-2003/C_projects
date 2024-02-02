#include <stdio.h>

void main (){

    int n, k, v, saida=0, i=0;

    scanf("%d%d", &n, &k);

    while (i < n){
        scanf("%d", &v);
        if( v == k){
            saida = 1;
        }
        i++;
    }
    printf("%d\n", saida);


}