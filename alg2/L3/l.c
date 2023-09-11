#include<stdio.h>
#include<string.h>

int main()
{
 FILE *file, *saida;
 file = fopen("entrada.txt", "r");
 
 char str[50];
 char format[] = {.txt};

 while((fscanf(file,"%s", str)) != EOF)
 {
   
   strcat(str, format);
   saida = fopen(str, "w");
   //fprintf(saida, "%s", temp);
 }
 
fclose(saida);
fclose(file);
return 0;
}