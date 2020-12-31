#include<stdio.h>
int f();// 声明

int main()
{
   int a,i;
   printf("输入数字\n");
   scanf("%d",&a);
   for(i=0;i<a;i++)
   {
       f();
   }
}

int f()
{
    printf("  *\n * *\n* * *\n * *\n  *\n");
    return 0;
}