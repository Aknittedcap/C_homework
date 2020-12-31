#include<stdio.h>
int Max,Min;
void score(int a[],int );
int main()
{
    int n,i;
    printf("intput numb of people\n");
    scanf("%d",&n);
    int a[n];
    printf("intput score: (%d people)\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    score(a,n);
}
void score(int a[],int n)
{
    int sum=0,i;
    float ave;
    Max=Min=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>=Max)
            Max=a[i];
        else if(a[i]<=Min)
            Min=a[i];
        sum=sum+a[i];
    }
    printf("Max=%d\nMin=%d\nfail:  ",Max,Min);
    for(i=0;i<n;i++)
    {
        if (a[i]<60)
            printf("%d ",a[i]);
        else 
            continue;
    }
    printf("\n");
    ave=sum/n;
    printf(">average:  ");
    for(i=0;i<n;i++)
    {
        if (a[i]>ave)
            printf("%d ",a[i]);
        else
            continue;
    }
    printf("\n");
    printf("<average:  ");
    for(i=0;i<n;i++)
    {
        if (a[i]<ave)
            printf("%d ",a[i]);
        else
            continue;
    }
}