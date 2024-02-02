#include <stdio.h>

void main () {

    int inicio;
    int fim;
    int sum;

    scanf("%d%d", &inicio, &fim);

    while (inicio <= fim)
    {
        printf("%d\n", inicio);
        sum = sum + inicio;
        inicio++;
    }
    
    printf("%d\n", sum);


}