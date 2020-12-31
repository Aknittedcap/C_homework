#include<stdio.h>
int jc(int);
int main()
{
    int n,i,sum=0;
    printf("enter n\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        sum=sum+jc(i);
    printf("sum=%d",sum);
}
int jc(int n)
{
    if(n==1||n==0)
        return 1;
    else
        return n*jc(n-1);
}