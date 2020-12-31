#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct STUDENT
{
    char name[20],first_name[20],last_name[20];
    float score;
    int age;
    STUDENT *NEXT;
}stu;
void Add_stu(stu *);
int Create_stu(stu *);
void Traversal_linked_list(stu *);
void Search_stu_by_name(stu *,char * );
void Search_stu_by_firstname(stu *,char *);
void Insert_stu(stu *,int );
main()
{
    stu *head=(stu *)malloc(sizeof(stu));
    head->NEXT=NULL;
    int power,num_of_stu;
    int m =1;
    printf("INITIALIZE STUDENTS 'S INFO:\n");
    num_of_stu=Create_stu(head);
    printf("NUMB OF STUDENTS: %d\n",num_of_stu);
    printf("*************************MENU************************\n0.exit\n1.input info of each student\n2.search student by name\n3.search student by surname\n4.add a student and insert it into the 2 position of the linked list\n5.add a student and insert it into the last position of the linked list\n");
    while (m!=0)
    {
        //printf("*************************MENU************************\n0.exit\n1.input info of each student\n2.search student by name\n3.search student by surname\n4.add a student and insert it into the 2 position of the linked list\n5.add a student and insert it into the last position of the linked list\n");
        printf("\nENTER N:  ");
        scanf("%d",&m);
        printf("\n");
        switch (m)
        {
            case 0 : break;
            case 1 : Traversal_linked_list(head);break;
            case 2 :
            {
                char name[20];
                printf("input name:  ");
                scanf("%s",name);
                char *point=name;
                Search_stu_by_name(head,point);
                printf("\n\n");
                break;
            }
            case 3:
            {
                char *firstname;
                char ftname[20];
                printf("输入要查找的姓:  ");
                scanf("%s",ftname);
                firstname=ftname;
                Search_stu_by_firstname(head,firstname);
                printf("\n\n");
                break;
            }
            case 4:
            {
                int n;
                printf("input the position where you want to insert the new student\n");
                scanf("%d",&n);
                Insert_stu(head,n);
                printf("success!\nDo you want to show the linked list 1/0\n");
                scanf("%d",&n);
                while(n==1)
                {
                    Traversal_linked_list(head);
                    n=0;
                }
                break;
            }
            case 5:
            {
                int n=1;
                printf("Do you want to insert the new student to the last one  1/0\n");
                scanf("%d",&n);
                while (n==1)
                {
                    Add_stu(head);
                    printf("success!\nDo you want to show the linked list 1/0\n");
                    scanf("%d",&n);
                    while(n==1)
                    {
                        Traversal_linked_list(head);
                        n=0;
                    }
                }
                break;
            }
        }
    }
}
//////////////////////////////////////
void Add_stu(stu *head)
{
    stu *temp=head;
    stu *new_stu=(stu *)malloc(sizeof(stu));
    while (temp->NEXT!=NULL)
        temp=temp->NEXT;
    temp->NEXT=new_stu;
    printf("输入姓:  ");
    scanf("%s",new_stu->name);
    printf("输入名:  ");
    scanf("%s",new_stu->last_name);
    strcpy(new_stu->first_name,new_stu->name);
    strcat(new_stu->name,new_stu->last_name);
    printf("input score :  ");
    scanf("%f",&new_stu->score);
    printf("input age:  ");
    scanf("%d",&new_stu->age);
    new_stu->NEXT=NULL;
}
/////////////////////////////////////////
int Create_stu(stu *head)
{
    int power,numb=0;
    printf("Continue or End 1/0\n");
    scanf("%d",&power);
    while (power==1)
    {
        Add_stu(head);
        printf("Continue or End 1/0\n");
        scanf("%d",&power);
        numb++;
    }
    return numb;
}
////////////////////////////////
void Traversal_linked_list(stu *head)
{
    stu *temp=head->NEXT;
    int numb=1;
    while (temp!=0)
    {
        printf("STUDENT_%d\nname: %s\nscore: %f\nage: %d\n",numb,temp->name,temp->score,temp->age);
        temp=temp->NEXT;
        numb+=1;
    }
}
///////////////////////////////////////
void Search_stu_by_name(stu *head,char *stu_name)
{
    int num=0;
    stu *temp=head->NEXT;
    while(temp!=NULL)
    {
        if (strcmp(stu_name,temp->name)==0)
        {
            printf("FIND IT!\nname:  %s\nscore:  %f\nage: %d\n",temp->name,temp->score,temp->age);
            num++;
        }
        temp=temp->NEXT;
    }
    if (num==0)
        printf("sorry,no such student\n");
}
/////////////////////////
void Search_stu_by_firstname(stu *head,char *firstname)
{
    int num=0;
    stu *temp=head->NEXT;
    while (temp!=NULL)
    {
        if (strcmp(temp->first_name,firstname)==0)
        {
            printf("%d :\nname: %s\nscore: %f\nage: %d\n\n",num+1,temp->name,temp->score,temp->age);
            num++;
        }
        temp=temp->NEXT;
    }
    if (num==0)
        printf("sorry,no such student\n");
}
void Insert_stu(stu *head,int n)
{
    stu *before_new_stu=head;
    for (int i=0;i<n-1;i++)
        before_new_stu=before_new_stu->NEXT;
    stu *after_new_stu=before_new_stu->NEXT;
    stu *new_stu=(stu *)malloc(sizeof(stu));
    before_new_stu->NEXT=new_stu;
    new_stu->NEXT=after_new_stu;
    printf("输入姓:  ");
    scanf("%s",new_stu->name);
    printf("输入名:  ");
    scanf("%s",new_stu->last_name);
    strcpy(new_stu->first_name,new_stu->name);
    strcat(new_stu->name,new_stu->last_name);
    printf("input score :  ");
    scanf("%f",&new_stu->score);
    printf("input age:  ");
    scanf("%d",&new_stu->age);
}