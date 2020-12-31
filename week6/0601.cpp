#include<stdio.h>
void sort(int a[]);
int main()
{
    int i;
    int a[10];
    printf("enter 10 numbs\n");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    sort(a);
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    return 0;
}
void sort(int a[])
{
    int i,j,temp;
    for(i=1;i<10;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(temp>=a[j])
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=temp;
    }
}