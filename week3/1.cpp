#include<stdio.h>
int f (int m,int n);
int main(void)
{
    int i=0,m,n,t;
    printf("enter m/n\n");
    scanf("%d %d",&m,&n);
    printf("0.");
    while (i<100 && m!=0)
    {
        m*=10;
        t=m/n;
        m%=n;
        i++;
        printf("%d",t);
    }
    return 0;
}