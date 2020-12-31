#include<stdio.h>
int Fibonacci(int );
main()
{
    int i,n;
    printf("input n\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        printf("F(%d)= %d\n",i+1,Fibonacci(i+1));
}
int Fibonacci(int n)
{
    int fib;
    if ((n==1)||(n==2))
        fib=1;
    else
        fib=Fibonacci(n-1)+Fibonacci(n-2);
    return fib;
}