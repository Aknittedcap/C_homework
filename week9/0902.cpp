//input quantity of numb of array
#include <stdio.h>
int num_len(char a[]);
main()
{
    int lenth;
    char a[50];
    printf("input string\n");
    gets(a);
    printf("numlenth = %d", num_len(a));
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
