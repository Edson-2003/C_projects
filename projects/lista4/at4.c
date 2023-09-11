#include <stdio.h>

void main () {

        int n;
    int i = 1;
    int sum = 0;

    scanf("%d", &n);

    for(; i <= n; i++)
    {
        if( ((i%2) != 0) )
        {
            sum = sum + i;
        }
    }

    printf("%d\n", sum);

}