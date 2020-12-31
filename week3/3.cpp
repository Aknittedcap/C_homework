10#include<stdio.h>
int check(int n);          
int main()
{
    int i,n,y,j=0;
    printf("input n\n");
    scanf("%d",&n);
    printf("\n");
    for(i=2;i<=n;i++)
    {
        y=check (i);
        if (y==i)
        {
            printf("%d ",i);
            j=j+i;
        }
        else    continue;
    }
    printf("\n");
    printf("和为  %d",j);
    return 0;
}
//define
int check (int n)
{
    int p,i=2;
    while (i<n)
    {
        p=n%i;
        i+=1;
        if (p==0)
        {
            return i;
            break;
        }
    }
    return i;
}