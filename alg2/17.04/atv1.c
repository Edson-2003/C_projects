#include <stdio.h>

    /*
    fopen
    fgetc / fputc
    fscanf / fprintf
    fgets / fputs
    fclose
    */
void main()
{


   FILE* fp;
   fp = fopen("entrada.txt", "r");
    
    fclose(fp);

}