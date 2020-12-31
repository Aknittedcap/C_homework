#include<stdio.h>
int f (int num);
int main()
{
    int n,i,y,p=2;
    printf("enter n\n");
    scanf("%d",&n);
    if(n>1)
    {
        for(i=1;i<=n;i++)
        {
            //printf("i=%d ",i);
            y=f(i);
            if(p<y)
            {
                p=y;
            }
            else
                continue;
        }
        printf("\n");
        printf("max=%d",p);
    }
    else    printf("error:n must bigger than 1");
    return 0;
}
//define
int f (int num)
{
    int sum,j;
    while (num!=0)
    {
        sum+=num%10;
        num/=10;
        //printf("sum=%d  ",sum);
    }
    //printf("\n");
    j=sum;
    sum=0;
    return j;
}