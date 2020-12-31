#include<stdio.h>
void f (int);
int main()
{
    int n;
    printf("enter n\n");
    scanf("%d",&n);
    f(n);
    return 0;
}
void f (int n)
{
   if(n>1)
   {
       f(n-1);
   }
   printf("%d ",n);
}