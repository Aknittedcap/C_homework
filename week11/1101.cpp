#include<stdio.h>
#include<stdlib.h>
void p_triangle(int ,FILE *);
main()
{
    FILE *f1;
    f1=fopen("d:\\Files\\Code\\test\\1111.txt","w");
    int n;
    printf("input line:  ");
    scanf("%d",&n);
    p_triangle(n,f1);
    fclose(f1);
}
void p_triangle(int n,FILE *file)
{
    int a,b;
    for(a=0;a<n;a++)
    {
        for(b=(n-a-1);b>0;b--)
            fprintf(file," ");
        for(b=0;b<(2*a+1);b++)
            fprintf(file,"*");
        if(a<n-1)
        fprintf(file,"\n");
    }
}