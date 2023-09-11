#include <stdio.h>

void func_Fibonacci (int N)
{
    int n1 =1,n2 =1, n3=0;
    
    if(N ==1 || N==2)
    {
    n3 = 1;
    }
    
    
    for (int i = 2; i<N; i++)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }
    printf ("%d ", n3);
    
}

void main()
{
    int n;
    scanf ("%d", &n);
    func_Fibonacci (n);
}
