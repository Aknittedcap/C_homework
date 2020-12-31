#include<stdio.h>
void in_sort(int a[],int);
int half_search(int a[],int ,int);
int main()
{
    int i,m,n,key;
    int a[10];
    printf("enter n\n");
    scanf("%d",&n);
    printf("enter 10 numbs\n");
    //scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    in_sort(a,n);
    printf("sort complete\nplz enter another numb:");
    scanf("%d",&key);
    m=half_search(a,n,key);
    //printf("m=%d\n",m);
    if(m!=0)
        printf("success!\nthe num 's location is %d",m+1);
    else
        printf("no such numb");
}
//升序
void in_sort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(temp<=a[j])
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=temp;
    }
}
//////////////////////////////////
//key是要查找的数
//n：从数组a[]的前n个数中查找key
//a[]为升序
//////////
int half_search(int a[],int n,int key)
{
    int low=0,high=n-1,mid;
    mid=(low+high)/2;
    while(low<=high)
    {
        if(a[mid]==key)
        {
            return mid;
        }
        else if (a[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
    return 0;
}