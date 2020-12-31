#include <stdio.h>
int list(int);
int main()
{
    int n;
    printf("enter n\n");
    scanf("%d",&n); 
    list(n);
    return 0;
}
int list(int m)
{
    int s1,s2;
    s1=m%10;
    s2=m/10;
    printf("%d",s1);
    if (s2>0)
        list(s2);
}