#include <stdio.h>

void decompoe(float x, int*p_int, float *p_frac)
{

    *p_int = (int) x;
    *p_frac = x - *p_int;   

}

void main()
{
    float num,b;
    int a;
    scanf("%f", &num);
    decompoe(num, &a, &b);

    printf("%d \n %f", a, b);


}