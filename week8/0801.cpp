#include<stdio.h>
void sbpoint (int a[],int,int *,int *,int *,int *);
int main()
{
    int n,maxnum,minnum,maxads,minads;
    printf("plz enter n\n");
    scanf("%d",&n);
    int a[n];
    printf("plz enter %d numbs\n",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sbpoint(a,n,&maxnum,&minnum,&maxads,&minads);
    printf("max = %d address=%d\nmin = %d address=%d",maxnum,maxads,minnum,minads);
    return 0;
}
void sbpoint (int a[],int n,int *maxnum,int *minnum,int *maxads,int *minads)
{
    int i,ads1=0,ads2=0,max=a[0],min=max;
    for(i=1;i<n;i++)
    {
        if(a[i]>=max)
        {
            max=a[i];
            *maxads=i;
        }
        if(a[i]<min)
        {
            min=a[i];
            *minads=i;
        }
    }
    *maxnum=max,*minnum=min;
}