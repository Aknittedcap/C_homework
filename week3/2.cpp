#include<stdio.h>
#include<math.h>
int main(void)
{
    int i,n,j=1;
    float m;
    float array[j];
    printf("enter n\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%f",&m);
        if (floor(m+0.5)==m)
        {
            array[j-1]=m;
            j+=1;
        }
        /*
        else
            continue;   */                                              //ck=true 存到数组
    }
     printf("output int:\n");
    if (j == 1)
    {
        printf("Sorry,no numb belongs int\n");
    }
    else
    {
        for (i = 0; i < (j-1); i++)
        {
            printf("%f ", array[i]);
        }
    }
    return 0;
}