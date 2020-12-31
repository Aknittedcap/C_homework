#include<stdio.h>
int main()
{
    int i;
    char c[20];
    for(i=0;i<20;i++)
        scanf("%c",c);
    for(i=0;i<20;i++)
        printf("%c",c[i]);
}