#include<stdio.h>
int in_sort(int a[],int n);
int pao_sort(int a[],int n);
int main()
{
    int n,i;
    int a[10],b[10];
    printf("enter__numbs\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<10;i++)
        b[i]=a[i];
    printf("in_sort'numbs= %d\npao_sort's numbs= %d",in_sort(a,n),pao_sort(b,n));
}
int in_sort(int a[],int n)
{
    int i,j,temp,num=0;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            num++;
            if(temp>a[j])
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=temp;
        num++;
    }
    return num;
}
int pao_sort(int a[],int n)
{
    int i,j,temp,num=0;
    for(i=0;i<n-1;i++)
    {
        num++;
        for(j=0;j<n-i;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            num++;
        }
    }
    return num;
}