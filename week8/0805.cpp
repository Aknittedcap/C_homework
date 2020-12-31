#include<stdio.h>
void Full_Permutation(char a[],int ,int );
void swap(char *,char *);
int slenth(char a[]);
main()
{
    int n;
    char a[100];
    printf("input string\n");
    scanf("%s",a);
    printf("Full Permutation:\n");
    n=slenth(a);
    Full_Permutation(a,0,n-1);
}
void swap(char *i,char *j)
{
    char temp;
    temp=*i;
    *i=*j;
    *j=temp;
}
//Full_Permutation:打印 a[stringbegin]-a[stringend]之间所有元素的全排列
void Full_Permutation(char a[],int stringbegin,int stringend)
{
    int i;
    if(stringbegin==stringend)
    {
        for(i=0;i<=stringend;i++)
            printf("-%c-",a[i]);
        printf("\n");
    }
    else
    {
        for(i=stringbegin;i<=stringend;i++)
        {
            swap(&a[stringbegin],&a[i]);
            Full_Permutation(a,stringbegin+1,stringend);
            swap(&a[stringbegin],&a[i]);
        }
    }
    
}
int slenth(char a[])
{
    int len=0;
    while (a[len]!=0)
    {
        len++;
    }
    return len;
}