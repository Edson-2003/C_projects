#include <stdio.h>
typedef struct
{
    float base;
    float altura;
}retangulo;

void lelados(retangulo *i)
{
    scanf("%f", &i->base);
    scanf("%f", &i->altura);
}

void main()
{
    retangulo r1;
    retangulo r2;

    lelados(&r1);
    lelados(&r2);

    float area1, area2, perimetro1, perimetro2;

    area1 = r1.altura * r1.base;
    area2 = r2.altura * r2.base;

    perimetro1 = 2 * (r1.base + r1.altura);
    perimetro2 = 2 * (r2.base + r2.altura);

    printf("%.2f %.2f %.2f %.2f",area1, perimetro1, area2, perimetro2);   
}