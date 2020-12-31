#include<stdio.h>
#define f1 1
#define f2 2
int stairs (int);
int main()
{
    int n;
    printf("enter n\n");
    scanf("%d",&n);
    printf("%d zhong",stairs(n));
}
int stairs (int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else
        return stairs(n-1)+stairs(n-2);
}