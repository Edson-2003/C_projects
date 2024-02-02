#include <stdio.h>

void main()
{
   int n,a;
   scanf("%d", &n);
   int vet[n];

   for(int i=0; i < n; i++)
   {
         scanf("%d", &vet[i]);
   }

   for(int i = 0; i < n; i++)
   {
        for( int j=0; j < n; j++)
        {
            if (vet [j] > vet [j+1])
            {   
                a = vet[j];
                vet [j] = vet [j+1];
                vet [j+1] = a;
            }
        }
   }
   for(int i = 0; i < n; i++)
   {
        printf("%d", vet [i]);
   }

}
