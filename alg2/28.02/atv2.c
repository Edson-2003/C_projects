#include <stdio.h>

int calcula_digitos(int n)
{
    int result = 0;
    while(n > 0)
    {
        n = n / 10;
        result ++;
    }
    return result;
}

void main()
{

    int n;
    scanf("%d", &n);

    int result = calcula_digitos(n);

    printf("%d", result);


}