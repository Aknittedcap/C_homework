#include<stdio.h>
struct Student
{
    char name[20];
    float score;
};
float Avescore(int ,Student student[]);
void Bigleg(int ,Student student[],float );
main()
{
    int i,n;
    float ave;
    printf("input the numb of students\n");
    scanf("%d",&n);
    Student student[n];
    for(i=0;i<n;i++)
    {
        printf("name of student%d:  ",i+1);
        scanf("%s",student[i].name);
        printf("score of student%d:  ",i+1);
        scanf("%f",&student[i].score);
        printf("\n");
    }
    ave=Avescore(n,student);
    printf("the average score:  %f\n\n",ave);
    Bigleg(n,student,ave);
}
float Avescore(int n,Student student[])
{
    int i;float sum=0;float ave;
    for(i=0;i<n;i++)
        sum=sum+student[i].score;
    ave=sum/n;
    return ave;
}
void Bigleg(int n,Student student[],float ave)
{
    int i;
    printf(">ave: \n\n");
    for(i=0;i<n;i++)
    {
        if (student[i].score>=ave)
            printf("student%d:  name:  %s  score:  %f\n",i+1,student[i].name,student[i].score);
        else
            continue;
    }
}