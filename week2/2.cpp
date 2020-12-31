#include<stdio.h>
int main()
{
    int m,n,i,p;
    p=0;
    printf("请输入数字\n");
    scanf("%d %d", &m,&n);
    for(i=1;i<n+1;i++)
    {
        if (m%i==0)
        {
            p=p+i;
        }
    }
    printf("%d",p);
    return 0;
}