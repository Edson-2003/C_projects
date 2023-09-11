#include <stdio.h>

int maior (int a, int b)
{
    int result;
    if( a > b)
    {
        result = a;
    }
    else
    {
        result = b;
    }
    return result;
}

void main() {

    int a, b;
    scanf("%d%d", &a, &b);
    printf("o maior valor é %d\n", maior(a,b));

}