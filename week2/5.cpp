#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    printf("your score is\n");
    if (80<a<=100) printf("A");
    else if (60<a<=80) printf("B");
    else if (40<a<=60) printf("C");
    else if (20<a<=40) printf("D");
    else printf("E");
    return 0;
}