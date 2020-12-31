//menu
#include <stdio.h>
#include <string.h>
///////////////////////////
int num_len(char a[]);
////////////////
void transform_S_B(char *);
////
struct Student
{
    char name[20];
    float score;
};
float Avescore(int, Student student[]);
void Bigleg(int, Student student[], float);
//////////
main()
{
    printf("=================Menu===================\n0.exit\n1.output the length of numbers\n2.conver big-small\n3.\n4.student\n");
    int n = 1;
    while (n != 0)
    {
        printf("enter n:  ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            int lenth;
            char a[50];
            printf("input string\n");
            scanf("%s", a);
            printf("numlenth = %d", num_len(a));
            break;
        case 2:
        {
            int i;
            char b[50];
            int len;
            printf("input string\n");
            scanf("%s", b);
            len = strlen(b);
            for (i = 0; i < len; i++)
                transform_S_B(&b[i]);
            puts(b);
            break;
        }
        case 3:
            break;
        case 4:
        {
            int i;
            int n;
            float ave;
            printf("input the numb of students\n");
            scanf("%d", &n);
            struct Student student[n];
            for (i = 0; i < n; i++)
            {
                printf("name of student%d:  ", i + 1);
                scanf("%s", student[i].name);
                printf("score of student%d:  ", i + 1);
                scanf("%f", &student[i].score);
                printf("\n");
            }
            ave = Avescore(n, student);
            printf("the average score:  %f\n\n", ave);
            Bigleg(n, student, ave);
            break;
        }
        }
        printf("\n");
    }
}
int num_len(char a[])
{
    int i = 0;
    int numblenth = 0;
    while (a[i] != 0)
    {
        if ((a[i] > 47) && (a[i] < 58))
            numblenth++;
        i++;
    }
    return numblenth;
}
/////////////
void transform_S_B(char *a)
{
    if ((*a > 64) && (*a < 91))
        *a = *a + 32;
    else if ((*a > 96) && (*a < 123))
        *a = *a - 32;
}
////////////////
float Avescore(int n, Student student[])
{
    int i;
    float sum = 0;
    float ave;
    for (i = 0; i < n; i++)
        sum = sum + student[i].score;
    ave = sum / n;
    return ave;
}
void Bigleg(int n, Student student[], float ave)
{
    int i;
    printf(">ave: \n\n");
    for (i = 0; i < n; i++)
    {
        if (student[i].score >= ave)
            printf("student%d:  name:  %s  score:  %f\n", i + 1, student[i].name, student[i].score);
        else
            continue;
    }
}