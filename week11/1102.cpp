#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct STUDENT
{
    char name[20];
    int age;
    float score;
    struct STUDENT *NEXT;
    struct STUDENT *PRIOR;
} stu;

main()
{
    int n;
    /*
    char *directory=(char *)malloc(sizeof(char));
    printf("input directory:\n");
    scanf("%s",directory);
    */
    char *d1 = (char *)"d:\\Files\\Code\\student.txt";
    stu *head = (stu *)malloc(sizeof(stu));
    head->PRIOR = NULL;
    head->NEXT = NULL;
    FILE *stu_info;
    int Count_stu(stu *head);
    void insert_stu(stu *, int);
    void Create_stu_list(char *, stu *);
    void Traversal_stu(stu *);
    void Save_to_file(stu *, float, char *directory);
    void Delete_stu(stu *, char *delete_name);
    printf("-----------------MENU------------------:\n0.exit\n1.read and show students' info\n2.add stu\n3.add 0.1 for score\n4.input a student's name and delete it\n\n");
    printf("enter n:  ");
    scanf("%d", &n);
    while (n != 0)
    {
        switch (n)
        {
        case 0:
            break;
        case 1:
        {
            Create_stu_list(d1, head);
            Traversal_stu(head);
            break;
        }
        case 2:
        {
            int n,numb;
            //printf("input the position where you want to insert the student\n");
            //scanf("%d",&n);
            insert_stu(head, 1);
            insert_stu(head, 4);
            numb=Count_stu(head);
            insert_stu(head, numb+1);
            Save_to_file(head, 0, d1);
            printf("Do you want to show the linked list 1/0\n");
            scanf("%d", &n);
            if (n == 1)
                Traversal_stu(head);
            break;
        }
        case 3:
            Save_to_file(head, 0.1, d1);
            printf("successfully.......\n\n");
            break;
        case 4:
        {
            char *d_name = (char *)malloc(sizeof(char));
            printf("input name of student who you want to delete it\n");
            scanf("%s", d_name);
            Delete_stu(head, d_name);
            Save_to_file(head, 0, d1);
            break;
        }
        }
        printf("enter n:  ");
        scanf("%d", &n);
    }
}
void Create_stu_list(char *directory, stu *head)
{
    FILE *stu_info = fopen(directory, "r");
    stu *temp = head;
    while (!feof(stu_info))
    {
        stu *new_stu = (stu *)malloc(sizeof(stu));
        temp->NEXT = new_stu;
        new_stu->PRIOR = temp;
        new_stu->NEXT = NULL;
        fscanf(stu_info, "%s %d %f\n", &new_stu->name, &new_stu->age, &new_stu->score);
        temp = temp->NEXT;
    }
    printf("read info successfully\n\n");
    fclose(stu_info);
}
int Count_stu(stu *head)
{
    int i=0;
    stu *temp=head->NEXT;
    while (temp!=NULL)
    {
        i++;
        temp=temp->NEXT;
    }
    return i;
}
void Traversal_stu(stu *head)
{
    stu *temp = head->NEXT;
    int i = 1;
    printf("SHOW INFO:\n\n");
    while (temp != NULL)
    {
        printf("STUDENT %d:\nname: %s\nage:  %d\nscore:  %f\n\n", i, &temp->name, temp->age, temp->score);
        i += 1;
        temp = temp->NEXT;
    }
}
void insert_stu(stu *head, int n)
{
    void insert_last(stu * head, int n);
    int Count_stu(stu *);
    int num;
    num=Count_stu(head);
    stu *temp = head;
    int i;
    if (n < (num+1))
    {
        for (i = 0; i < n; i++)
            temp = temp->NEXT;
        stu *new_stu = (stu *)malloc(sizeof(stu));
        stu *pp = temp->PRIOR;
        pp->NEXT = new_stu;
        new_stu->PRIOR = pp;
        new_stu->NEXT = temp;
        temp->PRIOR = new_stu;
        printf("POSITION:%d\ninput name:\n", n);
        scanf("%s", &new_stu->name);
        printf("input age:\n");
        scanf("%d", &new_stu->age);
        printf("input score:\n");
        scanf("%f", &new_stu->score);
    }
    else
        insert_last(head, n);
}
void insert_last(stu *head, int n)
{
    stu *temp = head;
    stu *new_stu = (stu *)malloc(sizeof(stu));
    while (temp->NEXT != NULL)
        temp = temp->NEXT;
    temp->NEXT = new_stu;
    new_stu->PRIOR = temp;
    new_stu->NEXT = NULL;
    printf("POSITION:%d\ninput name:\n", n);
    scanf("%s", &new_stu->name);
    printf("input age:\n");
    scanf("%d", &new_stu->age);
    printf("input score:\n");
    scanf("%f", &new_stu->score);
}
void Save_to_file(stu *head, float n, char *directory)
{
    stu *temp = head->NEXT;
    FILE *stu_info = fopen(directory, "w");
    while (temp != NULL)
    {
        if ((temp->NEXT) != NULL)
            fprintf(stu_info, "%s %d %f\n", &temp->name, temp->age, temp->score * (n + 1));
        else
            fprintf(stu_info, "%s %d %f", &temp->name, temp->age, temp->score * (n + 1));
        temp = temp->NEXT;
    }
    fclose(stu_info);
}
void Delete_stu(stu *head, char *d_name)
{
    int i = 0;
    stu *temp = head->NEXT;
    while (true)
    {
        if (strcmp(temp->name, d_name) == 0)
        {
            stu *pp = temp->PRIOR;
            stu *nn = temp->NEXT;
            free(temp);
            pp->NEXT = nn;
            i++;
            break;
        }
        temp = temp->NEXT;
    }
    if (i == 0)
        printf("no such student\n");
    else
        printf("successfully delete the student\n");
}