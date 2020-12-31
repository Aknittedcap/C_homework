#include<stdio.h>
void Bubble_Sort(int a[],int );
main ()
{
    int n,i;
    printf("input n\n");
    scanf("%d",&n);
    int a[n];
    printf("input %d numbs: \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("before sort: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    Bubble_Sort(a,n);
    printf("\n");
    printf("after sort: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
void Bubble_Sort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if (a[j]>=a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            else
                continue;
        }
    }
}