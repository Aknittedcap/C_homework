#include<stdio.h>
void bigger(int a[],int,int);
int main()
{
    int m,n;
    printf("enter n plz\n");
    scanf("%d",&n);
    int a[n];
    printf("enter %d numbs\n",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter another numb m\n");
    scanf("%d",&m);
    bigger(a,m,n);
    return 0;
}
void bigger(int a[],int m,int n)
{
    for(int i=0;i<n;i++)
    {
        if (m<a[i])
            printf("%d ",a[i]);
        else
            continue;
    }
}