#include <stdio.h>

// PROTÓTIPOS DOS PROCEDIMENTOS E DAS FUNÇÕES
void soma(float x, float y);
float soma2(float x, float y);
int parOuImpar(int x);
int mult(int x, int y);
void tabuada (int num);
float imc(float massa_kg, int altura_cm);
int imc_classif_num(float imc);
void classif_imc(float massa_kg, int altura_cm);

// FUNÇÃO MAIN()
int main(void)
{
    return 0;
}

// IMPLEMENTAÇÃO DOS PROCEDIMENTOS E DAS FUNÇÕES
void soma(float x, float y)
{
  printf("%.2f + %.2f = %.2f", x, y, x + y);
}

float soma2(float x, float y)
{
  return x + y;
}

int parOuImpar(int x)
{
  return x % 2 ? 1 : 0; 
}

int mult(int x, int y)
{
  return x * y;
}


void tabuada (int num)
{
  printf("===========================");
  printf("\n\t tabuada do %d\t\n", num)
  printf("===========================");
  for(int i = 1; i <= 10; i++)
  {
    printf("%d * %d = %d", i, num, num * i);
  }
}

float imc(float massa_kg, int altura_cm)
{
  return (massa_kg / ((altura_cm/100) * (altura/100)));  
}

int imc_classif_num(float imc)
{
  if(imc >= 40.0) return 4;
  if(imc >= 35.0) return 3;
  if(imc >= 30.0) return 2;
  if(imc >= 25.0) return 1;
  if(imc >= 18.0) return 0;
  return -1;
}

void classif_imc(float massa_kg, int altura_cm)
{
  float imc = imc(massa_kg, altura_cm);
  int classifica = classif_imc(imc)
  if(classifica == 4)
  {
    printf("")
  }
}
