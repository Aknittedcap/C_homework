#include<stdio.h>
void in_sort(int a[],int);
void swap(int *,int *);
int main()
{
    int i,n;
    int n1,n2;
    printf("input n\n");
    scanf("%d",&n);
    int a[n];
    printf("input %d numbers\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    in_sort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    printf("you want swap the value of array[_] &array[_]   ");
    scanf("%d %d",&n1,&n2);
    printf("before swap:\na[%d]= %d\na[%d]=%d\n",n1,a[n1],n2,a[n2]);
    swap(&a[n1],&a[n2]);
    printf("after swap:\na[%d]= %d\na[%d]=%d",n1,a[n1],n2,a[n2]);
}
void in_sort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if (temp<a[j])
                a[j+1]=a[j];
            else 
                break;
        }
        a[j+1]=temp;
    }
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

