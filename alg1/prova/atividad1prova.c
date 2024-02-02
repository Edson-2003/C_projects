#include <stdio.h>

void main () {

    int v1;
    int v2;
    int op;
    float res;

    scanf("%d%d%d", &v1, &op, &v2);

    if ( op == 0 ){
        res = v1 + v2;
    }

    if ( op == 1 ){
        res = v1 - v2;
    }

    if ( op == 2 ){
        res = v1 * v2;
    }

    if ( op == 3 ){
        res = v1 / v2;
    }

    printf("%.2f", res);

}