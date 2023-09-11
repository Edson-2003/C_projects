#include <stdio.h>

void main () {
    float p1,p2,t1,t2,m,sum;

    scanf("%f%f", &p1, &p2);
    scanf("%f %f", &t1, &t2);

    sum = p1 + p2 + t1 + t2;
    m = sum / 4;
    printf ("%.2f", m);

}