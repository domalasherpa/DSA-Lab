// program for reallocation
#include <stdio.h>
#include <stdlib.h>

void print(int *data, int n)
{
    printf("Data:\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(data + i));
    }
}

int main()
{
    int n, new;

    printf("Enter the size: ");
    scanf("%d", &n);

    int *data = (int *)malloc(n * sizeof(int));

    // takes the data input
    for (int i = 0; i < n; i++)
    {
        scanf("%d", data + i);
    }

    print(data, n);

    printf("enter new size: ");
    scanf("%d", &new);

    data = realloc(data, new * sizeof(int));

    printf("Enter new values: ");

    for (int i = 0; i < new; i++)
    {
        scanf("%d", data + i);
    }

    print(data, new);
    free(data);
    return 0;
}