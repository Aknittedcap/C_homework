#include<stdio.h>
#define N 20
#define M 30
void printscreen(int a[N][M]);
void check(int a[N][M]);
int main ()
{
    int a[N][M]={0};
    int i,j;
    a[6][8]=-1;
    a[8][4]=-1;
    a[10][14]=-1;
    a[12][10]=-1;
    a[13][10]=-1;
    a[2][3]=-1;
    a[15][7]=-1;
    //printscreen(a);
    check(a);
    printscreen(a);
}
void check(int a[N][M])
{
    int i,j,t,count=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            count=0;
            if (a[i][j]!=-1)
            {
                if(i>0&&j>0)
                    if (a[i-1][j-1]==-1)    count++;//左上
                if(i>0)
                    if (a[i-1][j]==-1)    count++;
                if(i>0&&j<M)
                    if (a[i-1][j+1]==-1)    count++;//右上
                if(j>0)
                    if (a[i][j-1]==-1)    count++;
                if(j<M)
                    if (a[i][j+1]==-1)    count++;
                if(i<N&&j>0)
                    if (a[i+1][j-1]==-1)    count++;
                if(i<N)
                    if (a[i+1][j]==-1)    count++;
                if(i<N&&j<M)
                    if (a[i+1][j+1]==-1)    count++;
                a[i][j]=count;
            }
        }
    }
}

void printscreen(int a[N][M])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(a[i][j]==0)  printf(" ");
            else if(a[i][j]==-1)    printf("*");
            else    printf("%d",a[i][j]);
        }
        printf("\n");
    }
}