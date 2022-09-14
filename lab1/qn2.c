// program to find the sum of n numbers using calloc function then deallocte the memory

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num, i;

    printf("How many numbers: ");
    scanf("%d", &num);

    int *a_num = (int *)calloc(num, sizeof(int));

    for (i = 0; i < num; i++)
    {
        scanf("%d", a_num + i);
    }

    // print the scanned numbers:

    for (i = 0; i < num; i++)
    {
        printf("\n%d", *(a_num + i));
    }

    free(a_num);
    return 0;
}