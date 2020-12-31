#include<stdio.h>
#include<stdlib.h>
typedef struct STUDENT
{
    int num;
    struct STUDENT *NEXT;
}stu;
void Create_circle_stu(stu * ,int );
//void Traversal_stu(stu *,int );
void out_sort(stu * );
main()
{
    int n;
    printf("enter numb of students\n");
    scanf("%d",&n);
    stu *first_student=(stu *)malloc(sizeof(stu));
    Create_circle_stu(first_student,n);
    printf("Now students start 1,2-leave-queue\n\n");
    out_sort(first_student);
}
void Create_circle_stu(stu *first_student,int n)
{
    stu *temp=first_student;
    for(int i=0;i<n;i++)
    {
        printf("STUDENT %d :\ninput numb:  ",i+1);
        scanf("%d",&temp->num);
        if (i<(n-1))
        {
            temp->NEXT=(stu *)malloc(sizeof(stu));
            temp=temp->NEXT;
            temp->NEXT=NULL;
            if (i==n-2)
                temp->NEXT=first_student;
        }
    }
}
void out_sort(stu *first_stu)
{
    int numb=1;
    stu *temp=first_stu;
    stu *p=NULL;
    while(first_stu!=first_stu->NEXT)
    {
        if(temp->NEXT==first_stu)
        {
            temp=first_stu;
            numb=1;
        }
        if ((numb+1)%2==0)
        {
            printf("Student num: %d is out\n",(temp->NEXT)->num);
            p=(temp->NEXT)->NEXT;
            free(temp->NEXT);
            temp->NEXT=p;
            temp=temp->NEXT;
            numb+=2;
        }
    }
}
/*
void Traversal_stu(stu *first_stu,int n)
{
    stu *temp=first_stu;
    for(int i=0;i<n;i++)
    {
        printf("STUDENT %d:\nNUM : %d\n",i+1,temp->num);
        temp=temp->NEXT;
    }
}
*/