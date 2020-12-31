//small to BBBBBBBBBBBBBig AND BBBBBBBBig to small
#include<stdio.h>
#include<string.h>
void transform_S_B(char *);
main()
{
    char a[50];int i,len;
    printf("input string\n");
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
        transform_S_B(&a[i]);
    puts(a);
}
void transform_S_B(char *a)
{
    if ((*a>64)&&(*a<91))
        *a+=32;
    else if ((*a>96)&&(*a<123))
        *a-=32;
}