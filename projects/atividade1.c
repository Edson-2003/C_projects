#include <stdio.h>

void main (){
    int v1, v3=0;
    

    scanf("%d", &v1);
    getchar();


    for(int i = 0; i <= v1 ; i++)
    {
        v3 = v1 + v3; 
        
    }
    printf("%d", v3);

    }