#include <stdio.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
}ponto;

void lecordenadas(ponto *i)
{
    scanf("%f", &i->x);
    scanf("%f", &i->y);
}

/*
  void imprimecoordenadas(coordenadas i)
    {

        printf("%f", i.x);
        printf("%f", i.y);
        printf("\n");

    }
*/

void main()
{
    ponto inicial;
    ponto final;
    
    lecordenadas(&inicial);
    lecordenadas(&final);

    double quadrx = (pow((final.y - inicial.y),2));
    double quadry = (pow((final.x - inicial.x),2));
    double distancia = sqrt(quadrx - quadry);

    printf("%.2f\n", distancia);
    //imprimecoordenadas(inicial);

}