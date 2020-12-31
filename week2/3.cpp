#include<stdio.h>
int main()
{
    int i,a,b;
    a=31;
    b=4;
    for(i=1;i<=a;i++)
    {
        printf("%d",i);
        if((i+b)%7==0)   printf("\n");
    }
    return 0;
}