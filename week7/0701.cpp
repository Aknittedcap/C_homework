#include<stdio.h>
#define N 20
#define M 50
void printscreen(int a[N][M]);
int main ()
{
    int a[N][M]={0};
    int i,j;
    //砖头
    for(i=0;i<2;i++)
    {
        for(j=0;j<M;j++)
            a[i][j]=1;
    }
    //挡板
    for(j=5;j<10;j++)
    {
        a[19][j]=2;
    }
    a[12][15]=9;
    printscreen(a);
    return 0;
}
void printscreen(int a[N][M])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if (a[i][j]==0)
                printf(" ");
            else if(a[i][j]==1)
                printf("*");
            else if(a[i][j]==2)
                printf("=");
            else if(a[i][j]==9)
                printf("o");
            else
                printf("");
        }
        printf("\n");
    }
}