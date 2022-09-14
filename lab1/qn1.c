// program to find the sum of n numbers using malloc function
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num, i, sum = 0;

    printf("How many numbers? : ");
    scanf("%d", &num);

    int *a_num = (int *)malloc(num * sizeof(int));

    // take the numbers:
    for (i = 0; i < num; i++)
    {
        scanf("%d", a_num + i);
    }

    // find the sum
    for (i = 0; i < num; i++)
    {
        // sum += a_num[i];
        sum += *(a_num + i);
    }

    printf("Sum of %d numbers is: %d", num, sum);

    free(a_num);
    return 0;
}