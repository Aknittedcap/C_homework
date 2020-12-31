#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct STUDENT
{
    int num;
    char name[20];
    float score;
    union
    {
        int p;
        char POS[20];
    } pos;
    struct STUDENT *next;
    struct STUDENT *prior;
} stu;
main()
{
    void Create_stu_ls(stu *, char *, char *);
    void Show_info(stu *);
    void Add_stu(stu *);
    void Delete_stu(stu *);
    void Modify_stu(stu *);
    stu *head = (stu *)malloc(sizeof(stu));
    char *directory1 = (char *)"d:\\Files\\Code\\C\\homework\\week12\\stu.dat";
    char *directory2 = (char *)"d:\\Files\\Code\\C\\homework\\week12\\stu_job.dat";
    int key;
    head->next = NULL;
    head->prior = NULL;
    printf("Initializing......\nSuccess!\n\n");
    Create_stu_ls(head, directory1, directory2);
    printf("*****MENU*****\n0.exit\n1.Show info\n2.Add a stu\n3.Delete a stu\n4.Modify a stu\n5.下次布置\n");
    do
    {
        printf("enter n:  ");
        scanf("%d", &key);
        switch (key)
        {
        case 0:
            break;
        case 1:
            Show_info(head);
            break;
        case 2:
        {
            int key2 = 0;
            Add_stu(head);
            printf("Do you want to show info?  1/0\n");
            scanf("%d", &key2);
            if (key2 == 1)
                Show_info(head);
            break;
        }
        case 3:
            Delete_stu(head);
            printf("Successfully delete.\n\n");
            break;
        case 4:
        {
            int key3 = 0;
            Modify_stu(head);
            printf("Do you want to show info? 1/0\n");
            scanf("%d", &key3);
            if (key3 == 1)
                Show_info(head);
            break;
        }
        case 5:
            break;
        default:
            break;
        }
    } while (key != 0);
}
void Create_stu_ls(stu *head, char *directory1, char *directory2)
{
    FILE *f1 = fopen(directory1, "r");
    FILE *f2 = fopen(directory2, "r");
    while ((f1 == NULL) || (f2 == NULL))
    {
        printf("error");
        exit(0);
    }
    stu *temp = head;
    while (!feof(f1))
    {
        stu *new_stu = (stu *)malloc(sizeof(stu));
        temp->next = new_stu;
        new_stu->prior = temp;
        new_stu->next = NULL;
        fscanf(f1, "%d %s  %f\n", &new_stu->num, new_stu->name, &new_stu->score);
        fscanf(f2, "%d\n", &((new_stu)->pos.p));
        temp = temp->next;
    }
    fclose(f1);
    fclose(f2);
}
void Show_info(stu *head)
{
    int i = 1;
    stu *temp = head->next;
    while (temp != NULL)
    {
        printf("STUDENT%d:\n", i);
        switch ((temp->pos).p)
        {
        case 1:
            strcpy((temp->pos).POS, "Monitor");
            break;
        case 2:
            strcpy((temp->pos).POS, "Party secretary");
            break;
        case 3:
            strcpy((temp->pos).POS, "Deputy monitor");
            break;
        case 4:
            strcpy((temp->pos).POS, "Common student");
            break;
        default:
            break;
        }
        printf("numb:%d name:%s score:%f    position:%s\n", temp->num, temp->name, temp->score, (temp->pos).POS);
        temp = temp->next;
        i++;
    }
    printf("\n\n");
}
void Add_stu(stu *head)
{
    int pos;
    stu *temp = head;
    printf("enter where do you want to insert the stu\nLocation:  ");
    scanf("%d", &pos);
    for (int i = 0; i < pos; i++)
        temp = temp->next;
    stu *new_stu = (stu *)malloc(sizeof(stu));
    if (temp == NULL)
    {
        temp = head;
        for (int i = 0; i < (pos - 1); i++)
            temp = temp->next;
        temp->next = new_stu;
        new_stu->prior = temp;
        new_stu->next = NULL;
    }
    else
    {
        (temp->prior)->next = new_stu;
        new_stu->prior = temp->prior;
        new_stu->next = temp;
        temp->prior = new_stu;
    }
    printf("input numb:\n");
    scanf("%d", &new_stu->num);
    printf("input name:\n");
    scanf("%s", new_stu->name);
    printf("input score:\n");
    scanf("%f", &new_stu->score);
    printf("input position: 1 --> Monitor   2 --> Party Secretary  3 --> Deputy Monitor   4 --> Common student\n");
    scanf("%d", &(new_stu->pos).p);
}
void Delete_stu(stu *head)
{
    stu *temp = head->next;
    char *d_name = (char *)malloc(sizeof(char));
    int num = 0;
    printf("input the name of student who you want to delete:\n");
    scanf("%s", d_name);
    while (temp != NULL)
    {
        if (strcmp(temp->name, d_name) == 0)
        {
            if (temp->next != NULL)
            {
                (temp->prior)->next = temp->next;
                (temp->next)->prior = temp->prior;
            }
            else
                (temp->prior)->next = NULL;
            free(temp);
            num++;
            break;
        }
        temp = temp->next;
    }
    if (num == 0)
        printf("No such stu\n");
}
void Modify_stu(stu *head)
{
    stu *temp = head->next;
    char *M_name = (char *)malloc(sizeof(stu));
    printf("input the name of stu who you want to modify.\n");
    scanf("%s", M_name);
    while (temp != NULL)
    {
        if (strcmp(temp->name, M_name) == 0)
            break;
        temp = temp->next;
    }
    printf("input numb:\n");
    scanf("%d", &temp->num);
    printf("input name:\n");
    scanf("%s", temp->name);
    printf("input score:\n");
    scanf("%f", &temp->score);
    printf("input position:\n");
    scanf("%d", &(temp->pos).p);
}