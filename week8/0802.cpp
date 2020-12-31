#include<stdio.h>
int charpoint(char a[],int *,int *,int *);
int main()
{
    int len,numnum,strnum,symnum;
    char a[100];
    printf("enter string\nno more than 100 numbs plz\n");
    gets(a);
    len=charpoint(a,&numnum,&strnum,&symnum);
    printf("lenth of string = %d\nquantity of number=%d\nquantity of charateristic=%d\nquantity of symbol=%d\n",len,numnum,strnum,symnum);
}
int charpoint(char a[],int *numnum,int *strnum,int *symnum)
{
    int numqut,strqut,symqut;
    int len=0;
    while(a[len]!=0) //结束字符'\0'的ASCII🐎为0
    {
        len++;
    }                 //=size of
    for(int i=0;i<len;i++)
    {
        if ((a[i]>47)&&(a[i]<58))
            numqut++;
        else if (((a[i]>64)&&(a[i]<81))||((a[i]>96)&&(a[i]<122)))
            strqut++;
        else
            symqut++;
    }
    *numnum=numqut,*strnum=strqut,*symnum=symqut;
    return len;
}