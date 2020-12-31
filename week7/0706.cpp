#include<stdio.h>
int f (int);
int main()
{
    int n;
    printf("enter n\n");
    scanf("%d",&n);
    printf("%d",f(n));
    return 0;
}
int f (int n)
{
    int s;
    if (n==1)
        s=1;
    else if (n==2)
        s=2;
    else 
        s=f(n-1)+f(n-2);
    return s;
}